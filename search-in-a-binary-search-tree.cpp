// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
