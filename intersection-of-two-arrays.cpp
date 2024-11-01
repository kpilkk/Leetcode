// two pointers

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> ans;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] == nums2[j])
            {
                if (ans.empty() || ans.back() != nums1[i])
                {
                    ans.push_back(nums1[i]);
                }
                ++i, ++j;
            }
            else if (nums1[i] < nums2[j])
            {
                ++i;
            }
            else
            {
                ++j;
            }
        }
        return ans;
    }
};

// two sets

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> ans;

        for (auto& i : s2)
        {
            if (s1.find(i) != s1.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};