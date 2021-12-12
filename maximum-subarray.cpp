// Kedane's algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int local_max = nums[0];
        int global_max = local_max;
        
        for(int i=1;i<nums.size();++i){
            local_max = max(nums[i], local_max+nums[i]);
            global_max = max(local_max, global_max);
        }
        return global_max;
    }
};
