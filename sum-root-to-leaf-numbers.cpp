// https://leetcode.com/problems/sum-root-to-leaf-numbers/

// DFS recursion
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int val, int &ans){
        if(!root)
            return;
        
        val = val * 10 + root -> val;
        if(root -> left == root -> right)
            ans += val;
        dfs(root -> left, val, ans);
        dfs(root -> right, val, ans);
    }
};
