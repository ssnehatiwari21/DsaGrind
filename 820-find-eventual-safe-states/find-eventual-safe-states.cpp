class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> ans;
        queue<int> q;
        vector<int> vis(graph.size(),0);
        vector<int> indegree(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            for(int nei:graph[i]){
                indegree[i]++;
                adj[nei].push_back(i);
            }
        }
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.push_back(top);
            for(int nei:adj[top]){
                indegree[nei]-=1;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};