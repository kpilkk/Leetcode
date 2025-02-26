#include <iostream>
#include <stack>
using namespace std;

// Define the structure of a BST node
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int value) : key(value), left(nullptr), right(nullptr) {}
};

// Function to remove keys outside the given range iteratively
// Node *removeKeysOutsideRange(Node *root, int min, int max)
// {
//     if (!root)
//         return nullptr;

//     // Stack for iterative traversal
//     stack<Node **> stk;
//     stk.push(&root);

//     while (!stk.empty())
//     {
//         Node **curr = stk.top();
//         stk.pop();

//         if (!*curr)
//             continue;

//         // If the current node's key is less than the min
//         if ((*curr)->key < min)
//         {
//             Node *rightChild = (*curr)->right;
//             delete *curr;
//             *curr = rightChild;
//             stk.push(curr); // Recheck the current position
//         }
//         // If the current node's key is greater than the max
//         else if ((*curr)->key > max)
//         {
//             Node *leftChild = (*curr)->left;
//             delete *curr;
//             *curr = leftChild;
//             stk.push(curr); // Recheck the current position
//         }
//         // If the current node's key is within the range
//         else
//         {
//             stk.push(&((*curr)->left));
//             stk.push(&((*curr)->right));
//         }
//     }

//     return root;
// }

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

// Utility function to insert a new node into the BST
Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Utility function to print the BST in-order
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;

    // Create the BST
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);

    cout << "Original BST: ";
    inorder(root);
    cout << endl;

    int min = -10, max = 13;

    // Remove keys outside the range [-10, 13]
    root = removeKeysOutsideRange(root, min, max);

    cout << "Modified BST: ";
    inorder(root);
    cout << endl;

    return 0;
}