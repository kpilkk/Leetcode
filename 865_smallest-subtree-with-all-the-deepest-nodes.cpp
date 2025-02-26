// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/

/**
 * Definition for a binary tree node.
 */

#include <unordered_map>
#include <iostream>

using namespace std;

class TreeNode
{

public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    unordered_map<TreeNode *, int> mp;
    int max_depth;

public:
    void dfs(TreeNode *root, int depth)
    {
        if (root)
        {
            mp[root] = depth;
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }

    TreeNode *answer(TreeNode *root)
    {
        if (root == nullptr || mp[root] == max_depth)
            return root;

        TreeNode *L = answer(root->left), *R = answer(root->right);

        if (L != nullptr && R != nullptr)
            return root;

        if (L != nullptr)
            return L;

        if (R != nullptr)
            return R;

        return nullptr;
    }

    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        mp.clear();

        dfs(root, 0);

        max_depth = -1;

        for (auto &itr : mp)
        {
            max_depth = max(max_depth, itr.second);
        }

        return answer(root);
    }
};

int main()
{
    Solution obj;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    TreeNode *temp = obj.subtreeWithAllDeepest(root);
    return 0;
}
