class Solution {
public:
    vector<int> parent;
    vector<int> size;
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        //dsu initialisation
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
        int freeedges=0;
        for(int i=0;i<connections.size();i++){
            if(find(connections[i][0])==find(connections[i][1])) freeedges++;
            unionbysize(connections[i][0],connections[i][1]);
            
        }
        int connectedcomponent=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) connectedcomponent++;
        }
        if(connectedcomponent-1>freeedges) return -1;
        return connectedcomponent-1;
    }
};