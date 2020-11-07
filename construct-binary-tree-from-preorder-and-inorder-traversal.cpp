// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Recursive solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    TreeNode* helper(vector<int>& preorder, int i, int m, vector<int>& inorder, int j, int n){
        if(i == m || j == n)
            return nullptr;
        
        int mid = find(inorder.begin() + j, inorder.begin() + n, preorder[i]) - inorder.begin();
        
        TreeNode* root = new TreeNode(preorder[i]);
        
        root -> left = helper(preorder, i + 1, i + 1 + mid - j, inorder, j , mid);
        root -> right = helper(preorder, i + 1 + mid - j, m, inorder, mid + 1, n);
        
        return root;
    }
};
