class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        //overall time complexity is O(n^2logn) and space complexity is O(n)

        int n=matrix[0].size();
        set<int> sr;
        set<int> sc;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sr.insert(matrix[i][j]); //logn
            }
            if(sr.size()!=n) return false; //log1
            sr.clear();//log1
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sc.insert(matrix[j][i]);
            }
            if(sc.size()!=n) return false;
            sc.clear();
        }

        return true;
    }
};