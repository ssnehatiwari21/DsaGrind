class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int w=flights[i][2];
            adj[u].push_back({v,w});
        }
        queue<pair<int,pair<int,int>>> pq; //node,level,price
        vector<int> pricefinal(n,1e9);
        pq.push({src,{1,0}});
        pricefinal[src]=0;
        while(!pq.empty()){
            int node=pq.front().first;
            int level=pq.front().second.first;
            int price=pq.front().second.second;
            pq.pop();
            for(auto nei:adj[node]){
                int neinode=nei.first;
                int neiprice=nei.second;
                if(neiprice+price<pricefinal[neinode] && level<=k+1){
                    pricefinal[neinode]=neiprice+price;
                    pq.push({neinode,{level+1,neiprice+price}});
                }
            }
        }
        if(pricefinal[dst]==1e9) return -1;
        return pricefinal[dst];
    }
};