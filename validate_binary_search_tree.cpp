/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        
        TreeNode *curr = root, *prev=NULL;
        stack<TreeNode*> s;
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }
            
            curr = s.top();
            s.pop();
            if(prev!=NULL && prev->val>=curr->val) return false;
            prev = curr;
            curr = curr->right;
        }
        return true;
    }
};
