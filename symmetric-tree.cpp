// https://leetcode.com/problems/symmetric-tree/

// Recursive solution
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
    
    bool isSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr)
            return false;
        return (left -> val == right -> val) && isSymmetric(left -> right, right -> left) && isSymmetric(left -> left, right -> right);
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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> bfs;
        bfs.push(root);
        bfs.push(root);
        while(!bfs.empty()){
            auto left = bfs.front();
            bfs.pop();
            auto right = bfs.front();
            bfs.pop();
            if(!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left  -> val != right -> val)
                return false;
            bfs.push(left -> left);
            bfs.push(right -> right);
            bfs.push(left -> right);
            bfs.push(right -> left);
        }
        return true;
    }
};
