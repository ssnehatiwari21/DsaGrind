class Solution {
public:
    bool dfs(vector<int>& arr, int index,vector<int> &vis){
        //option-1
        if(index>=arr.size() || index<0) return false;
        if(vis[index]==1) return false;
        if(arr[index]==0) return true;
        //option1
        vis[index]=1;
        bool option1=dfs(arr,index+arr[index],vis);
        //option2
        bool option2=dfs(arr,index-arr[index],vis);

        return option1||option2;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> vis(arr.size(),0);
        return dfs(arr,start,vis);
    }
};