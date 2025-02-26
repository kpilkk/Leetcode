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

#include <unordered_map>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    unordered_map<TreeNode *, int> um;
    int max_depth;

    void dfs(TreeNode *root, int depth)
    {
        if (root != nullptr)
        {
            um[root] = depth;
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
    }

    TreeNode *answer(TreeNode *root)
    {
        if (root == nullptr || um[root] == max_depth)
            return root;

        TreeNode *left = answer(root->left), *right = answer(root->right);

        if (left != nullptr && right != nullptr)
            return root;
        if (left != nullptr)
            return left;
        if (right != nullptr)
            return right;

        return nullptr;
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        um.clear();
        max_depth = -1;
        dfs(root, 0);

        for (auto &itr : um)
        {
            max_depth = max(max_depth, itr.second);
        }

        return answer(root);
    }
};