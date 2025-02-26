#include <vector>

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

// O(n) solution with O(n) spacce
class Solution
{

    bool findPath(TreeNode *root, vector<TreeNode *> &path, int val)
    {
        if (root == nullptr)
            return false;

        path.push_back(root);

        if (root->val == val || findPath(root->left, path, val) || findPath(root->right, path, val))
            return true;

        path.pop_back();
        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path1;
        vector<TreeNode *> path2;

        findPath(root, path1, p->val);
        findPath(root, path2, q->val);

        int i;
        for (i = 0; i < path1.size() && i < path2.size(); ++i)
        {
            if (path1[i] != path2[i])
                break;
        }

        return path1[i - 1];
    }
};

// O(n) solution with space optimization
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val == p->val || root->val == q->val)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;

        return left ? left : right;
    }
};