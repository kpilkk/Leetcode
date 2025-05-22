#include <algorithm>
#include <iostream>

struct Node
{
    int key;
    int height;
    Node *left, *right;
    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

int height(Node *n)
{
    return n ? n->height : 0;
}

int balanceFactor(Node *n)
{
    return n ? (height(n->left) - height(n->right)) : 0;
}

Node *rightRotate(Node *n)
{
    Node *x = n->left;
    Node *temp = x->right;
    x->right = n;
    n->left = temp;
    n->height = 1 + std::max(height(n->left), height(n->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
}

Node *leftRotate(Node *n)
{
    Node *x = n->right;
    Node *temp = x->left;
    x->left = n;
    n->right = temp;
    n->height = 1 + std::max(height(n->left), height(n->right));
    x->height = 1 + std::max(height(x->left), height(x->right));
    return x;
}

Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = balanceFactor(node);

    // Left Left Case
    //     30
    //    /
    //  20
    //  /
    // 10   <- Inserted here (causes imbalance at 30)
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    // Right Right Case
    // 10
    //    \
    //    20
    //      \
    //      30  <- Inserted here (causes imbalance at 10)
    else if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    // Left Right Case
    //     30
    //    /
    //  20
    //    \
    //    25  <- Inserted here (causes imbalance at 30)
    else if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Right Left Case
    // 10
    //    \
    //    30
    //    /
    //  20  <- Inserted here (causes imbalance at 10)
    else if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    std::cout << root->key << " ";
    inorder(root->right);
}

int main()
{
    Node *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // The AVL tree is now balanced
    inorder(root); // Function to print the tree in-order
    return 0;
}