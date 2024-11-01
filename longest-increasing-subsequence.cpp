// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>

using namespace std;

// Brute force using recursion computing all
class Solution
{
    int lengthOfLIS(vector<int>& nums, int idx, int n)
    {
        if (idx == 0)
            return 1;

        int mx = 1;
        for (int i = 0; i < idx; ++i)
        {
            if (nums[i] < nums[idx])
                mx = max(mx, 1 + lengthOfLIS(nums, i, n));
        }

        return mx;
    }
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int ret = 1, n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            ret = max(ret, lengthOfLIS(nums, i, n));
        }
        return ret;
    }
};

// Top-down with Memoization

class Solution
{
    int dp[2501];

    int lengthOfLIS(vector<int>& nums, int idx, int n)
    {
        if (idx == 0)
            return 1;

        if (dp[idx] != -1)
            return dp[idx];

        int mx = 1;
        for (int i = 0; i < idx; ++i)
        {
            if (nums[i] < nums[idx])
                mx = max(mx, 1 + lengthOfLIS(nums, i, n));
        }

        return dp[idx] = mx;
    }
public:
    Solution()
    {
        memset(dp, 0xff, sizeof(dp));
    }
    int lengthOfLIS(vector<int>& nums)
    {
        int ret = 1, n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            ret = max(ret, lengthOfLIS(nums, i, n));
        }
        return ret;
    }
};

// Binary Search

// Explanation - https://leetcode.com/problems/longest-increasing-subsequence/solutions/1326308/c-python-dp-binary-search-bit-segment-tree-solutions-picture-explain-o-nlogn

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> subs;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (subs.empty() || subs.back() < nums[i])
                subs.push_back(nums[i]);
            else
            {
                auto it = lower_bound(subs.begin(), subs.end(), nums[i]);
                *it = nums[i];
            }
        }

        return subs.size();
    }
};