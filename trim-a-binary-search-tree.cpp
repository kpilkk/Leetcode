// https://leetcode.com/problems/trim-a-binary-search-tree/description/

#include <iostream>
#include <stack>

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
    // BST
    //          6
    //       /    \
    //     -13     14
    //       \    /  \
    //       -8 13    15
    //         /
    //        7
public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return nullptr;

        TreeNode *left = trimBST(root->left, low, high);
        TreeNode *right = trimBST(root->right, low, high);

        if (root->val >= low && root->val <= high)
        {
            root->left = left;
            root->right = right;
            return root;
        }
        else if (root->val < low)
        {
            return right;
        }
        else
        {
            return left;
        }
    }
};

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Iterative
Node *removeKeysOutsideRange(Node *root, int low, int high)
{
    Node *dummy = new Node(0); // Dummy node to handle root updates
    dummy->left = root;        // Attach root to dummy node for easier parent tracking
    Node *parent = dummy;
    Node *curr = root;
    bool isLeftChild = true; // Tracks if the current node is a left or right child

    while (curr)
    {
        if (curr->key < low || curr->key > high)
        {
            // Node is out of range, remove it
            Node *temp = curr;
            if (curr->key < low)
            {
                curr = curr->right; // Move to the right subtree
            }
            else
            {
                curr = curr->left; // Move to the left subtree
            }
            if (isLeftChild)
            {
                parent->left = curr; // Update parent's left child
            }
            else
            {
                parent->right = curr; // Update parent's right child
            }
            delete temp; // Free memory
        }
        else
        {
            // Node is within range, proceed to next child
            parent = curr;
            if (curr->left)
            {
                curr = curr->left;
                isLeftChild = true;
            }
            else if (curr->right)
            {
                curr = curr->right;
                isLeftChild = false;
            }
            else
            {
                // Both children are null, backtrack to parent
                curr = nullptr;
            }
        }
    }

    Node *newRoot = dummy->left;
    delete dummy; // Clean up dummy node
    return newRoot;
}

// Iterative with stack
Node *removeKeysOutsideRange(Node *root, int min, int max)
{
    if (!root)
        return nullptr;

    // Stack for iterative traversal
    stack<Node **> stk;
    stk.push(&root);

    while (!stk.empty())
    {
        Node **curr = stk.top();
        stk.pop();

        if (!*curr)
            continue;

        // If the current node's key is less than the min
        if ((*curr)->key < min)
        {
            Node *rightChild = (*curr)->right;
            delete *curr;
            *curr = rightChild;
            stk.push(curr); // Recheck the current position
        }
        // If the current node's key is greater than the max
        else if ((*curr)->key > max)
        {
            Node *leftChild = (*curr)->left;
            delete *curr;
            *curr = leftChild;
            stk.push(curr); // Recheck the current position
        }
        // If the current node's key is within the range
        else
        {
            stk.push(&((*curr)->left));
            stk.push(&((*curr)->right));
        }
    }

    return root;
}

void printInorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(-13);
    root->right = new TreeNode(14);
    root->left->right = new TreeNode(-8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(15);
    root->right->left->left = new TreeNode(7);

    printInorder(root);
    cout << endl;
    int low = -10, high = 13;

    Solution obj;
    TreeNode *ans = obj.trimBST(root, low, high);
    printInorder(ans);
    return 0;
}