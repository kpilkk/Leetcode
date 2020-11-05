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

// Concise solution of the above
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        return 1 + max(maxDepth(root -> left), maxDepth(root -> right));
    }
};

// BFS iterative solution
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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        int ans = 0;
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()){
            ++ans;
            for(int i = 0, n = bfs.size(); i < n; ++i){
                TreeNode* temp = bfs.front();
                bfs.pop();
                
                if(temp -> left)
                    bfs.push(temp -> left);
                if(temp -> right)
                    bfs.push(temp -> right);
            }
        }
        return ans;
    }
};
