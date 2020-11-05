// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// DFS recursion
Solution {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;
        maxDepth(root, 1, &ans);
        return ans;
    }
    
    void maxDepth(TreeNode* root, int val, int *ans){
        if(!root)
            return;
        if(root -> left == root -> right)
            *ans = max(val, *ans);
        
        maxDepth(root -> left, val + 1, ans);
        maxDepth(root -> right, val + 1, ans);
    }
};
