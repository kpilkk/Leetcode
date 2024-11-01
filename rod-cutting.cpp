// DP
// https://www.geeksforgeeks.org/cutting-a-rod-dp-13/
// Brute force considering all solutions

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cutRod(int price[], int n)
    {
        //code here
        if (n == 0)
            return 0;

        int ret = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            ret = max(ret, price[i - 1] + cutRod(price, n - i));
        }
        return ret;
    }
};

// Top-down with Memoization Solution

class Solution
{
    int dp[1001];
public:
    Solution()
    {
        memset(dp, 0xff, sizeof(dp));
    }

    int cutRod(int price[], int n)
    {
        //code here
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ret = INT_MIN;
        for (int i = 1; i <= n; ++i)
        {
            ret = max(ret, price[i - 1] + cutRod(price, n - i));
        }

        return dp[n] = ret;
    }
};

// Bottom-Up Method

class Solution
{
    int dp[1001];
    int s[1001]; // To stor best cut
public:
    Solution()
    {
        memset(dp, 0xff, sizeof(dp));
        memset(s, 0x0, sizeof(s));
    }

    int cutRod(int price[], int n)
    {
        //code here
        if (n == 0)
            return 0;

        dp[0] = 0;

        for (int i = 1; i <= n; ++i)
        {
            int ret = INT_MIN;
            for (int j = 1; j <= i; ++j)
            {
                if (ret < price[j - 1] + dp[i - j])
                {
                    ret = price[j - 1] + dp[i - j];
                    s[i] = j;
                }
            }
            dp[i] = ret;
        }

        return dp[n];
    }
};