// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

// Approach #1 Using HashSet
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
    bool findTarget(TreeNode* root, int k) {
        set<int> temp;
        
        return find(root, k, temp);
    }
    
private:
    bool find(TreeNode *root, int k, set<int>& temp){
        if(root == NULL)
            return false;
        if(temp.find(k-root->val)!=temp.end())
            return true;
        temp.emplace(root->val);
        return find(root->left, k, temp) || find(root->right, k, temp);
    }
};
