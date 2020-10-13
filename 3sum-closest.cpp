// https://leetcode.com/problems/3sum-closest/

// Two pointer
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; ++i){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                    return sum;
                if(abs(target - sum) < abs(target - diff))
                    diff = sum;
                else if(sum > target)
                    --r;
                else
                    ++l;
            }
        }
        return diff;
    }
};
