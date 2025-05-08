// https://leetcode.com/problems/balance-a-binary-search-tree/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

// Approach:
// 1. Perform an inorder traversal of the BST to get the sorted values.
// 2. Use the sorted values to build a balanced BST.
// 3. The middle element of the sorted array will be the root of the balanced BST.
// 4. Recursively build the left and right subtrees using the left and right halves of the sorted array.
// 5. Return the root of the balanced BST.
// Time Complexity: O(n), where n is the number of nodes in the BST.
// Space Complexity: O(n), for storing the inorder traversal of the BST.

class Solution
{
    void inorder(TreeNode *root, vector<int> &inorderNode)
    {
        if (root == nullptr)
            return;

        inorder(root->left, inorderNode);
        inorderNode.push_back(root->val);
        inorder(root->right, inorderNode);
    }

    TreeNode *buildBalancedTree(vector<int> &inorderNode, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(inorderNode[mid]);
        root->left = buildBalancedTree(inorderNode, start, mid - 1);
        root->right = buildBalancedTree(inorderNode, mid + 1, end);

        return root;
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<int> inorderNode;

        inorder(root, inorderNode);

        return buildBalancedTree(inorderNode, 0, inorderNode.size() - 1);
    }
};