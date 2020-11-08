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

// Similar to stack implementation of inorder traversal with only 1 line difference
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack;
        
        while(root || !stack.empty()){
            while(root){
                ans.emplace_back(root -> val);
                stack.emplace(root);
                root = root -> left;
            }
            root = stack.top();
            stack.pop();
            root = root -> right;
        }
        
        return ans;
    }
};

// Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        while(root){
            if(root -> left){
                TreeNode* pre = root -> left;
                while(pre -> right && pre -> right != root){
                    pre = pre -> right;
                }
                if(pre -> right){
                    pre -> right = nullptr;
                    root = root -> right;
                }
                else{
                    pre -> right = root;
                    ans.emplace_back(root -> val);
                    root = root -> left;
                }
            }
            else{
                ans.emplace_back(root -> val);
                root = root -> right;
            }
        }
        
        return ans;
    }
};
