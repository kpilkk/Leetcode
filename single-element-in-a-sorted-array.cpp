// https://leetcode.com/problems/single-element-in-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

// Using XOR in O(n)

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int ans = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            ans ^= nums[i];
        }

        return ans;
    }
};

// Using binary search in O(logn)

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;

        // int mid;
        while (l < r)
        {
            int mid = (l + r) / 2;

            if (mid % 2 == 1)
                mid -= 1;

            if (nums[mid] == nums[mid + 1])
            {
                l = mid + 2;
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];
    }
};