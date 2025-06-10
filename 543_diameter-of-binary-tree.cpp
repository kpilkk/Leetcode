// https://leetcode.com/problems/diameter-of-binary-tree/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
using namespace std;

class Solution
{
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int D1 = height(root->left) + height(root->right);
        int D2 = diameterOfBinaryTree(root->left);
        int D3 = diameterOfBinaryTree(root->right);

        return max({D1, D2, D3});
    }
};

// Better time complexity

class Solution
{
    int dfs(TreeNode *root, int &result)
    {
        if (root == nullptr)
            return 0;

        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);
        return 1 + max(left, right);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        dfs(root, result);
        return result;
    }
};