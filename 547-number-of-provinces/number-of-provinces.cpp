class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void unionbyrank(int u,int v){
        int x=find(u);
        int y=find(v);
        if(rank[x]>rank[y]){
            parent[y]=x;
        }else if(rank[x]<rank[y]){
            parent[x]=y;
        }else{
            parent[x]=y;
            rank[y]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {

        parent.resize(isConnected.size());
        rank.resize(isConnected.size(),0);
        for(int i=0;i<isConnected.size();i++) parent[i]=i;

        for(int i=0;i<isConnected.size();i++){
            for(int j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1 && i!=j){
                    unionbyrank(i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<parent.size();i++){
            if(parent[i]==i) count++;
        }
        return count;
    }
};