class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //create a adjlist
        vector<vector<pair<int,int>>> adj(n+1);
        vector<int> distance(n+1,1e9);
        distance[0]=-1;
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int wt=times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        distance[k]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto nei:adj[node]){
                int neinode=nei.first;
                int neidis=nei.second;
                if(neidis+dis<distance[neinode]){
                    distance[neinode]=neidis+dis;
                    pq.push({neidis+dis,neinode});
                }
            }
        }
        int time = *max_element(distance.begin(), distance.end());
        if(time==1e9) return -1;
        return time;

    }
};