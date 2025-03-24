// https://leetcode.com/problems/optimal-partition-of-string/

#include <unordered_set>
#include <string>

using namespace std;

// Using hashset

class Solution
{
public:
    int partitionString(string s)
    {
        int ans = 0;

        int n = s.length();
        int i = 0;

        unordered_set<char> um;
        while (i < n)
        {
            if (um.find(s[i]) != um.end())
            {
                um.clear();
                ++ans;
            }
            um.insert(s[i++]);
        }

        if (!um.empty())
            ++ans;

        return ans;
    }
};

// Using bit manipulation

class Solution
{
public:
    int partitionString(string s)
    {
        int ans = 1;  // At least one partition is needed
        int used = 0; // Bitmask to track used characters

        for (const char c : s)
        {
            const int i = c - 'a'; // Convert 'a' to 'z' into index 0-25

            if ((used >> i) & 1)
            {                  // Check if the bit at position i is set
                used = 1 << i; // Reset used and start a new substring
                ++ans;         // Increment partition count
            }
            else
            {
                used |= 1 << i; // Mark character as used in bitmask
            }
        }

        return ans;
    }
};