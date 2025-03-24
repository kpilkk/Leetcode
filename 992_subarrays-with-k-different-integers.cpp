// https://leetcode.com/problems/subarrays-with-k-different-integers/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    unordered_map<int, int> um;
    int subarrayWithAtmostKDistinct(const vector<int> &nums, int k)
    {
        int count = 0;
        int left = 0, right = 0;
        int n = nums.size();

        um.clear();

        while (right < n)
        {
            if (um[nums[right]] == 0)
            {
                --k;
            }
            um[nums[right]]++;

            while (k < 0)
            {
                um[nums[left]]--;
                if (um[nums[left]] == 0)
                    ++k;
                ++left;
            }

            // The intuition behind (right – left + 1) is that it counts all possible subarrays
            // that end at right and start at any index between left and right.
            count += (right - left + 1);
            ++right;
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return subarrayWithAtmostKDistinct(nums, k) - subarrayWithAtmostKDistinct(nums, k - 1);
    }
};