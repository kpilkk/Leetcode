// https://leetcode.com/problems/delete-node-in-a-bst/

// Recursive solution
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(key < root -> val)
            root -> left = deleteNode(root -> left, key);
        else if(key > root -> val)
            root -> right = deleteNode(root -> right, key);
        else{
            if(!root -> left)
                return root -> right;
            else if(!root -> right)
                return root -> left;
            TreeNode* minNode = findMin(root -> right);
            root -> val = minNode -> val;
            root -> right = deleteNode(root -> right, minNode -> val);
        }
        return root;
    }
    
    TreeNode* findMin(TreeNode* root){
        while(root -> left)
            root = root -> left;
        return root;
    }
};
