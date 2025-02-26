
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

// Using Binary Search Property
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);

        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

// Excluding stack space
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
            return nullptr;

        while (root != nullptr)
        {
            if (root->val > p->val && root->val > q->val)
                root = root->left;

            else if (root->val < p->val && root->val < q->val)
                root = root->right;

            else
                break;
        }

        return root;
    }
};