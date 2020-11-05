// https://leetcode.com/problems/binary-tree-level-order-traversal/

// BFS iterative solution
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        while(!bfs.empty()){
            vector<int> level;
            int n = bfs.size();
            for(int i = 0; i < n; ++i){
                auto temp = bfs.front();
                bfs.pop();
                level.emplace_back(temp -> val);
                if(temp -> left)
                    bfs.push(temp -> left);
                if(temp -> right)
                    bfs.push(temp -> right);
            }
            ans.emplace_back(level);
        }
        return ans;
    }
};
