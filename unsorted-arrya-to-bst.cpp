#include <iostream>
#include <vector>
using namespace std;

// Node structure for the BST
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST
Node* insert(Node* root, int value)
{
    if (!root)
    {
        return new Node(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to create BST from an unsorted array
Node* createBST(const vector<int>& arr)
{
    Node* root = nullptr;
    for (int value : arr)
    {
        root = insert(root, value);
    }
    return root;
}

// Helper function to print inorder traversal of BST
void inorderTraversal(Node* root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main()
{
    vector<int> arr = { 10, 5, 1, 7, 40, 50 };
    Node* root = createBST(arr);

    cout << "Inorder Traversal of BST: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}
