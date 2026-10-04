class Solution {
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //dsu initialisation
        int n=accounts.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        unordered_map<string, int> mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                    mp[accounts[i][j]]=i;
                }else{
                    unionbysize(mp[accounts[i][j]],i);
                }
            }
        }
        vector<vector<string>> mergeans(n);
        for(auto it:mp){
            string mail=it.first;
            int idx=find(it.second);
            mergeans[idx].push_back(mail);
        }
        vector<vector<string>> ans;
        
        for(int i=0;i<mergeans.size();i++){
            if(mergeans[i].size()==0) continue;
            sort(mergeans[i].begin(),mergeans[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j=0;j<mergeans[i].size();j++){
                temp.push_back(mergeans[i][j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};