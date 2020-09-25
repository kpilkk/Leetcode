// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

// Brute Force : TLE
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        for(int i = 0; i < n; ++i){
            int temp = 0;
            for(int j = i + 1; j < n; ++j){
                if(nums[j] < nums[i])
                    ++temp;
            }
            counts[i] = temp;
        }
        return counts;
    }
};
