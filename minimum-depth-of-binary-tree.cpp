// https://leetcode.com/problems/minimum-depth-of-binary-tree/

// DFS recursive solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        if(!root -> left)
            return 1 + minDepth(root -> right);
        if(!root -> right)
            return 1 + minDepth(root -> left);
        
        return 1 + min(minDepth(root -> left), minDepth(root -> right));
    }
};

// BFS iterative solution
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        int ans = 1;
        while(!bfs.empty()){
            for(int i = 0, n = bfs.size(); i < n;++i){
                TreeNode* temp = bfs.front();
                bfs.pop();
                if(temp -> left == temp -> right)
                    return ans;
                if(temp -> left)
                    bfs.push(temp -> left);
                if(temp -> right)
                    bfs.push(temp -> right);
            }
            ++ans;
        }
        return ans;
    }
};
