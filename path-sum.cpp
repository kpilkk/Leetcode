// https://leetcode.com/problems/path-sum/

// Recursive solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        
        if(root -> left == nullptr && root -> right == nullptr)
            return sum == root -> val;
                       
        return hasPathSum(root -> left, sum - (root -> val)) || hasPathSum(root -> right, sum - (root -> val));
    }
};

// BFS iterative solution
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({root, 0});
        while(!bfs.empty()){
            auto temp = bfs.front();
            bfs.pop();
            int s = temp.first -> val + temp.second;
            if((temp.first -> left == temp.first -> right) && s == sum)
                return true;
            if(temp.first -> left)
                bfs.push({temp.first -> left, s});
            if(temp.first -> right)
                bfs.push({temp.first -> right, s});
        }
        return false;
    }
};
