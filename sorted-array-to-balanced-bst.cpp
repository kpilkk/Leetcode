// https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution
{
    Node* sortedArrayToBST(vector<int>& nums, int start, int end)
    {
        if (start > end)
            return nullptr;

        int mid = (start + end) / 2;

        Node* head = new Node(nums[mid]);
        head->left = sortedArrayToBST(nums, start, mid - 1);
        head->right = sortedArrayToBST(nums, mid + 1, end);

        return head;
    }
public:
    Node* sortedArrayToBST(vector<int>& nums)
    {
        // Code here
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }
};