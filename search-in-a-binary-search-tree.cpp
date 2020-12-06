// https://leetcode.com/problems/search-in-a-binary-search-tree/

// Recursive solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return root;
        if(val < root -> val)
            return searchBST(root -> left, val);
        else if(val > root -> val)
            return searchBST(root -> right, val);
        else
            return root;
    }
};

// Iterative solution
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root)
            return root;
        while(root){
            if(root -> val == val)
                return root;
            if(val < root -> val)
                root = root -> left;
            else
                root = root -> right;
        }
        return nullptr;
    }
};
