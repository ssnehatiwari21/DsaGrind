/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void postorderTraversal(Node* root, vector<int> &ans){
        if(root==nullptr) return;

        for(Node* child:root->children){
            postorderTraversal(child,ans);
        }
        ans.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(root==nullptr) return {};
        vector<int> ans;
        postorderTraversal(root,ans);
        return ans;
    }
};