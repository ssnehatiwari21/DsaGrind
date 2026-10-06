class Solution {
    vector<int> parent;
    vector<int> size;
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void unionbysize(int u,int v){
        int x=find(u);
        int y=find(v);
        if(x==y) return;
        if(size[x]>=size[y]){
            parent[y]=x;
            size[x]+=size[y];
        }else{
            parent[x]=y;
            size[y]+=size[x];
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        //dsu initialisation
        parent.resize(n*n);
        size.resize(n*n,1);
        for(int i=0;i<n*n;i++) parent[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nodeval=i*n+j;
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int neirow=i+dir[k][0];
                        int neicol=j+dir[k][1];
                        if(neirow>=0 && neicol>=0 && neirow<n && neicol<n && grid[neirow][neicol]==1){
                            int neival=neirow*n+neicol;
                            if(find(neival)!=find(nodeval)){
                                unionbysize(neival,nodeval);
                            }
                        }
                    }
                }
            }
        }
        int maxsize=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> s;
                    int sizestep=1;
                    for(int k=0;k<4;k++){
                        int nr=i+dir[k][0];
                        int nc=j+dir[k][1];
                        if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==1){
                            s.insert(find(nr*n+nc));
                        }                        
                    }
                    for(auto e:s){
                            sizestep+=size[e];
                    }
                    maxsize=max(maxsize,sizestep);
                }
            }
        }
        if(maxsize==0) return n*n;
        return maxsize;
    }
};