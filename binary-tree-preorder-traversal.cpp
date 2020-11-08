// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Recursive solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
    
    void helper(TreeNode* root, vector<int>& ans){
        if(!root)
            return;
        
        ans.emplace_back(root -> val);
        helper(root -> left, ans);
        helper(root -> right, ans);
    }
};
