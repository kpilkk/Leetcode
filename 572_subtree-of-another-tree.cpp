// https://leetcode.com/problems/subtree-of-another-tree/description/

#include "headers.h"

class Solution
{
    bool isSame(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr && subRoot == nullptr)
            return true;

        if (root == nullptr || subRoot == nullptr)
            return false;

        if (root->val != subRoot->val)
            return false;

        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        if (root == nullptr)
            return false;

        if (isSame(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

// Serialization

class Solution
{
public:
    void serialize(TreeNode *root, string &s)
    {
        if (!root)
        {
            s += "#,";
            return;
        }
        s += "," + to_string(root->val);
        serialize(root->left, s);
        serialize(root->right, s);
    }

    bool isSubtree(TreeNode *s, TreeNode *t)
    {
        string s1, s2;
        serialize(s, s1);
        serialize(t, s2);
        return s1.find(s2) != string::npos;
    }
};