// https://leetcode.com/problems/longest-common-subsequence

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Top-down memoization

class Solution
{
    int memo[1001][1001];

    int LCS(string& text1, string& text2, int m, int n)
    {
        if (m == text1.length() || n == text2.length())
            return 0;

        if (memo[m][n] != -1)
            return memo[m][n];

        if (text1[m] == text2[n])
            return memo[m][n] = 1 + LCS(text1, text2, m + 1, n + 1);

        return memo[m][n] = max(LCS(text1, text2, m + 1, n), LCS(text1, text2, m, n + 1));
    }
public:
    Solution()
    {
        memset(memo, 0xff, sizeof(memo));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        return LCS(text1, text2, 0, 0);
    }
};

// Bottom-Up Tabulation
class Solution
{
    int memo[1001][1001];

public:
    Solution()
    {
        memset(memo, 0x0, sizeof(memo));
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (text1[i - 1] == text2[j - 1])
                    memo[i][j] = 1 + memo[i - 1][j - 1];
                else
                    memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
            }
        }

        return memo[m][n];
    }
};