/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int tilt(TreeNode* root,int &sum){
        if(root==nullptr) return 0;
        int l=tilt(root->left,sum);
        int r=tilt(root->right,sum);
        sum+=abs(l-r);
        return l+r+root->val;
    }
    int findTilt(TreeNode* root) {
        int ans=0;
        tilt(root,ans);
        return ans;
    }
};