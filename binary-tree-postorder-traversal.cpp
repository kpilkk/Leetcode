// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Recursive solution
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    
    void helper(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        helper(root -> left, ans);
        helper(root -> right, ans);
        ans.emplace_back(root -> val);
    }
};
