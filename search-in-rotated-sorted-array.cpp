// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(target == nums[mid])
                return mid;
            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && nums[mid] >= target)
                    r = mid;
                else
                    l = mid + 1;
            }
            else{
                if(nums[mid] <= target && nums[r] >= target)
                    l = mid;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};
