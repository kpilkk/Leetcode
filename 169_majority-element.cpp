// Question -> https://leetcode.com/problems/majority-element/
// Boyer-Moore Majority Voting Algorithm -> https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

#include <vector>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int mElement = 0, count = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                mElement = nums[i];
                count = 1;
            }
            else if (mElement == nums[i])
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        count = 0;

        for (int x : nums)
        {
            if (x == mElement)
                ++count;
        }

        if (count > nums.size() / 2)
            return mElement;

        return -1;
    }
};