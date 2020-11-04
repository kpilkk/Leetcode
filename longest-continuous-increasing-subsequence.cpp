// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

// One pass solution
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int n = nums.size();
        int ans = 1 , i = 0;
        
        while(i < n){
            int temp = i;
            while(i < n - 1 && nums[i] < nums[i + 1])
                ++i;
            ans = max(ans, i - temp + 1);
            ++i;
        }
        return ans;
    }
};
