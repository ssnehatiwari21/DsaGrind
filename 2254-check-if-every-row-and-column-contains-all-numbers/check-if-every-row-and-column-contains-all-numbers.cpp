class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        set<int> sr;
        set<int> sc;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sr.insert(matrix[i][j]);
            }
            if(sr.size()<n) return false;
            sr.clear();
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sc.insert(matrix[j][i]);
            }
            if(sc.size()<n) return false;
            sc.clear();
        }

        return true;
    }
};