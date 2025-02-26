// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <unordered_set>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;
// Brute Force : Time Limit Exceded
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (allUnique(s, i, j))
                    ans = max(ans, j - i);
            }
        }
        return ans;
    }

private:
    bool allUnique(string s, int start, int end)
    {
        set<char> temp;
        for (int i = start; i < end; ++i)
        {
            char ch = s[i];
            if (temp.find(ch) != temp.end())
                return false;
            temp.emplace(ch);
        }
        return true;
    }
};

// 2nd slution
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // bool isCharSet[100] = {false};
        unordered_set<char> mp;

        int left = 0, right = 0;

        int maxLength = 0;
        while (right < s.length())
        {
            while (mp.find(s[right]) != mp.end())
            {
                mp.erase(s[left]);
                ++left;
            }
            // isCharSet[s[right] - 'a'] = true;
            mp.insert(s[right]);
            maxLength = max(maxLength, (right - left) + 1);
            right++;
        }

        return maxLength;
    }
};

// 3rd solution

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> um;

        int maxAns = 0, right = 0, left = -1;

        while (right < s.length())
        {
            if (um.find(s[right]) != um.end())
            {
                int temp = left;
                left = um[s[right]];
                for (int i = temp + 1; i <= left; ++i)
                {
                    um.erase(s[i]);
                }
            }
            um[s[right]] = right;
            maxAns = max(maxAns, right - left);
            ++right;
        }

        return maxAns;
    }
};
