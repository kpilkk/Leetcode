// https://leetcode.com/problems/count-of-range-sum/

// Naive solutiom : TLE

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sum(n + 1, 0);
        for(int i = 0; i < n; ++i)
            sum[i + 1] = sum[i] + nums[i];
        
        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = i + 1; j <= n; ++j)
                if(sum[j] - sum[i] >= lower && sum[j] - sum[i] <= upper)
                    ++ans;
        return ans;
    }
};
