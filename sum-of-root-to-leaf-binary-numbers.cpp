// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

// preorder DFS solution
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int val, int& ans){
        if(!root)
            return;
        val = val << 1 | root -> val;
        if(root -> left == root -> right)
            ans += val;
        dfs(root -> left, val, ans);
        dfs(root -> right, val, ans);
    }
};
