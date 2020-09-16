// https://leetcode.com/problems/single-number-ii/submissions/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            int temp = ones;
            ones = (nums[i] ^ ones) & ~twos;
            twos = (nums[i] & temp & ~twos) | (~nums[i] & ~temp & twos);
        }
        return ones;
    }
};
