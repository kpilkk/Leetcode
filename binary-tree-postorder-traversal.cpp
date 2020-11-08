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

// Iterative solution using stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack;
        TreeNode* last = nullptr;
        while(root || !stack.empty()){
            while(root){
                stack.emplace(root);
                root = root -> left;
            }
            TreeNode* temp = stack.top();
            if(temp -> right && last != temp -> right)
                root = temp -> right;
            else{
                ans.emplace_back(temp -> val);
                last = temp;
                stack.pop();
            }
        }
        return ans;
    }
};
