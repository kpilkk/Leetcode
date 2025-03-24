// https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

// Divide and Conquer

#include <string>
#include <algorithm>

using namespace std;

class Solution
{
    int longestSubstring(const string &s, int l, int r, int k)
    {
        int ret = 0;

        int freq[26] = {0};
        for (int i = l; i < r; ++i)
        {
            freq[s[i] - 'a'] += 1;
        }

        for (int i = l; i < r; ++i)
        {
            if (freq[s[i] - 'a'] < k)
            {
                int left = longestSubstring(s, l, i, k);
                int right = longestSubstring(s, i + 1, r, k);
                return max(left, right);
            }
        }

        return (r - l);
    }

public:
    int longestSubstring(string s, int k)
    {
        int ans = 0;

        return longestSubstring(s, 0, s.length(), k);
    }
};