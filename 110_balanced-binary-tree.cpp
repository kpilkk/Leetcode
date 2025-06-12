// https://leetcode.com/problems/balanced-binary-tree/

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

// Brute force -> O(n^2)
class Solution
{
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

public:
    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// Optimized - O(n) time
class Solution
{
    int balanced(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftHeight = balanced(root->left);
        int rightHeight = balanced(root->right);

        if (leftHeight == -1 || rightHeight == -1 || abs(rightHeight - leftHeight) > 1)
            return -1;

        return max(leftHeight, rightHeight) + 1;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return balanced(root) >= 0;
    }
};