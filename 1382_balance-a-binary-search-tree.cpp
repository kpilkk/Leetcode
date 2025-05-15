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

/*
DSW (Day-Stout-Warren) Algorithm Explanation:
The DSW algorithm balances a binary search tree in two main steps:
1. Transform the BST into a "vine" (a right-skewed linked list) using right rotations.
2. Convert the vine into a balanced BST by performing a series of left rotations at specific nodes.

Steps:
- Make a vine: Traverse the tree, rotating left children up to form a right-only chain.
- Balance the vine: Calculate the number of nodes, then perform left rotations to reduce the height and balance the tree.

Time Complexity: O(n)
Space Complexity: O(1) (in-place, ignoring recursion stack)
*/

#include <math.h>
class Solution
{
    void makeVine(TreeNode *dummy)
    {
        TreeNode *root = dummy->right;

        while (root)
        {
            if (root->left)
            {
                TreeNode *temp = root->left;
                root->left = temp->right;
                temp->right = root;
                dummy->right = temp;
                root = temp;
            }
            else
            {
                dummy = root;
                root = root->right;
            }
        }
    }

    int Count(TreeNode *root)
    {
        int count = 0;
        while (root)
        {
            ++count;
            root = root->right;
        }
        return count;
    }

    void compress(TreeNode *root, int m)
    {
        TreeNode *dummy = root;
        root = root->right;

        for (int i = 0; i < m; ++i)
        {
            TreeNode *temp = root->right;
            root->right = temp->left;
            temp->left = root;
            dummy->right = temp;
            dummy = temp;
            root = temp->right;
        }
    }

public:
    TreeNode *balanceBST(TreeNode *root)
    {
        TreeNode dummy = TreeNode(0);
        dummy.right = root;

        makeVine(&dummy);

        int n = Count(dummy.right);

        int m = (1 << (int)log2(n + 1)) - 1;

        compress(&dummy, n - m);

        for (m /= 2; m > 0; m /= 2)
        {
            compress(&dummy, m);
        }
        return dummy.right;
    }
};