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

// Iterative solution using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack;

        while(root || !stack.empty()){
            if(root){
                ans.emplace_back(root -> val);
                if(root -> right)
                    stack.emplace(root -> right);
                root = root -> left;
            }
            else{
                root = stack.top();
                stack.pop();
            }
        }
        
        return ans;
    }
};
