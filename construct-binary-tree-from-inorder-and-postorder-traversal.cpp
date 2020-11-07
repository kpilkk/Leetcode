// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// Recursive solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, 0, inorder.size(), postorder, 0 , postorder.size());
    }
    
    TreeNode* helper(vector<int>& inorder, int i, int m, vector<int>& postorder, int j, int n){
        if(i == m || j == n)
            return nullptr;
        
        int root_val = postorder[n - 1];
        TreeNode* root = new TreeNode(root_val);

        int mid = find(inorder.begin() + i, inorder.begin() + m, root_val) - inorder.begin();

        root -> left = helper(inorder, i, mid, postorder, j, j + mid - i);
        root -> right = helper(inorder, mid + 1, m, postorder, j + mid - i, n - 1);
        
        return root;
    }
};
