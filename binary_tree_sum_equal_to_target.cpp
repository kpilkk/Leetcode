/*
 * Amazon Interview question -> https://leetcode.com/discuss/post/6466327/amazon-sde-1-round-2-by-anonymous_user-di2f/
 * Given a binary tree, you need to find a pair of two nodes such that their sum of values is equal to target.
 * Constraints:
 * 1: distance between two nodes should be equal to d
 * 2: both nodes should not be at same level
 * return true if found any such pair of nodes
 * Note: tree can contain duplicate values
 */

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *findLCA(TreeNode *root, int n1, int n2)
{
    if (root == nullptr)
        return root;

    if (root->val == n1 || root->val == n2)
        return root;

    TreeNode *leftLCA = findLCA(root->left, n1, n2);
    TreeNode *rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA && rightLCA)
        return root;

    return leftLCA ? leftLCA : rightLCA;
}

int calculateDistance(TreeNode *root, int u, int v, unordered_map<int, int> mp)
{
    // lowest common ancesstor of 2 node u and v
    TreeNode *LCA = findLCA(root, u, v);

    if (LCA == NULL)
    {
        return -1;
    }

    // Disatnce between 2 node
    int distance = mp[u] + mp[v] - 2 * mp[LCA->val];
    return distance;
}

bool optimal_findPair(TreeNode *root, int target, int d)
{
    // Time complexity: O(n)
    // Space complexity: O(n)

    /* Intuition: We perform a level order traversal and while traversing we keep track of node and its level into the map.

         1
        /  \
       2    3
      / \  / \
     4   5 6  7

    So for each node we search  (target - curr->val) into the map.
    e.g. target = 9, d=3, currentNode = 7, mp={1:0, 2:1, 3:1, 4:2, 5:2, 6:2, 7:2}
    required = 9-7 = 2 (2 is present in the map and its level is 1)
    we found a pair i.e {2,7}.

    Now validate with constraints i.e
    1. level should be different
    2. distance between 2 node should be equla to d

    for above example:
    1. two node sum = target. 2+7=9
    2. are node are at different level which is true
    3. distance between 2 node is 3 which is equal to d

    In the brute solution, the findDistanceBetweenNodes function is called for every valid pair, which involves finding the LCA and then calculating the distance. This makes the time complexity O(n^2) in the worst case.

    Optimization:

         1
        /  \
       2    3
      / \  / \
     4   5 6  7

    formula for Disatnce between 2 node:

        distance = (level[u] + level[v] − 2×level[LCA(u,v)])

        E.g u=4, v=5
        distance = 2 + 2 - 2*1 = 2

        Q. Why we use 2×level[LCA(u,v)] ?
        Ans: if i use (level[u] + level[v]) then distance becomes 4 (see in diagram) which is wrong, correct ans is 2 that's wgy we use 2×level[LCA(u,v)].
    */

    if (root == NULL)
    {
        return false;
    }

    // map to store node and level;
    unordered_map<int, int> mp;

    queue<TreeNode *> q;
    q.push(root);
    int level = 0;

    // performing level order traversal
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();

            // searching for required in map to form pair - (required, curr->val)
            int required = target - curr->val;

            // map the current node with its level in
            mp[curr->val] = level;

            // check if required is present in map.
            // if present check for its level, if level are dfferent.
            // check if distance between these 2 node is equal to d
            // if all true we find our pair
            if (mp.find(required) != mp.end())
            {
                // check if both are in different level
                if (mp[curr->val] != mp[required])
                {
                    int distance = calculateDistance(root, curr->val, required, mp);

                    // check if distance between 2 nodes is equal to d
                    if (distance == d)
                    {
                        // we find our pair
                        cout << curr->val << " " << required << endl;
                        return true;
                    }
                }
            }

            // insert left to queue
            if (curr->left)
            {
                q.push(curr->left);
            }

            // insert right to queue
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        // increment level
        level++;
    }

    // no pair found
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int target = 7;
    int d = 2;

    // 2. optimal solution
    bool result = optimal_findPair(root, target, d);
    if (result)
    {
        cout << "Pair found" << endl;
    }
    else
    {
        cout << "No pair found" << endl;
    }
}