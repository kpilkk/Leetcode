// https://leetcode.com/problems/validate-binary-search-tree/

// recursive solution
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }
    
    bool isValid(TreeNode* root, int* lower, int* upper){
        if(!root)
            return true;

        if(upper && root -> val >= *upper)
            return false;
        if(lower && root -> val <= *lower)
            return false;
        
        return isValid(root -> left, lower, &(root -> val)) && isValid(root -> right, &(root -> val), upper);
    }
};

// stack based solution - iterative
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
