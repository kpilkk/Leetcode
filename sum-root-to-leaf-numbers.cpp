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

// BFS iterative : beats 100% runtime
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        
        queue<pair<TreeNode*, int>> bfs;
        bfs.push(make_pair(root, root -> val));
        pair<TreeNode*, int> curr;
        
        while(!bfs.empty()){
            curr = bfs.front();
            bfs.pop();
            
            if(curr.first -> left == curr.first -> right)
                ans += curr.second;
            
            if(curr.first -> left)
                bfs.push(make_pair(curr.first -> left, (curr.second * 10 + curr.first -> left -> val)));
            if(curr.first -> right)
                bfs.push(make_pair(curr.first -> right, (curr.second * 10 + curr.first -> right -> val)));
        }
        return ans;
    }
};
