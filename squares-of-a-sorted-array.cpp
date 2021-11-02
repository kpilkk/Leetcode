// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int n = nums.size() - 1;
        
        int l = 0;
        int r = n;
        
        while(n >= 0){
            if(abs(nums[l]) < abs(nums[r])){
                ans[n--] =  pow(nums[r--], 2);
            }
            else{
                ans[n--] =  pow(nums[l++], 2);
            }
        }
        return ans;
    }
};