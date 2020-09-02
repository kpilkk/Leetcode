// Iteratively
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Using Stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while(curr!=NULL || !s.empty()){
            while(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }
        return ans;
    }
};

// Morris Traversal

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *pre = NULL;
        
        while(root!=NULL){
            if(root->left==NULL){
                ans.push_back(root->val);
                root=root->right;
            }
            else{
                pre = root->left;
                while(pre->right!=NULL && pre->right!=root){
                    pre = pre->right;
                }
                if(pre->right==NULL){
                    pre->right = root;
                    root = root->left;
                }
                else{
                    pre->right=NULL;
                    ans.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return ans;
    }
};

// Using Recursion

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& ans){
        if(root!=NULL){
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right, ans);
        }
    }
};
