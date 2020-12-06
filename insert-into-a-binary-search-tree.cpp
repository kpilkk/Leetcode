// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// Recursive solution
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            root = new TreeNode(val);
        else if(val < root -> val)
            root -> left = insertIntoBST(root -> left, val);
        else
            root -> right = insertIntoBST(root -> right, val);
        return root;
    }
};
