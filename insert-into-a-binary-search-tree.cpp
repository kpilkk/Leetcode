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

// Iterative solution
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        TreeNode *temp = root, *pre = nullptr;
        while(root){
            pre = root;
            if(val < root -> val){
                root = root -> left;
            }
            else{
                root = root -> right;
            }
        }
        if(val < pre -> val)
            pre -> left = new TreeNode(val);
        else
            pre -> right = new TreeNode(val);
        return temp;
    }
};
