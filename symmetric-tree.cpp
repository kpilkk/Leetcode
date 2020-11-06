// https://leetcode.com/problems/symmetric-tree/

// Recursive solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        return (left -> val == right -> val) && isSymmetric(left -> right, right -> left) && isSymmetric(left -> left, right -> right);
    }
};
