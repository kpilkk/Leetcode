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

// BFS iterative solution
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<pair<TreeNode*, int>> bfs;
        bfs.push(make_pair(root, root -> val));
        
        int ans = 0;
        pair<TreeNode*, int> curr;
        while(!bfs.empty()){
            curr = bfs.front();
            bfs.pop();
            
            if(curr.first -> left == curr.first -> right)
                ans += curr.second;
            
            if(curr.first -> left)
                bfs.push(make_pair(curr.first -> left, (curr.second << 1 | curr.first -> left -> val)));
            if(curr.first -> right)
                bfs.push(make_pair(curr.first -> right, (curr.second << 1 | curr.first -> right -> val)));
        }
        return ans;
    }
};
