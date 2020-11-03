// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while(l <= r){
            // int mid = l + (r - l) / 2;
            int mid = (l + r) >> 1;
            if(nums[mid] == target)
                return true;
            
            else if(nums[l] < nums[mid]){
                if(nums[l] <= target && nums[mid] > target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else if(nums[l] > nums[mid]){
                if(nums[r] >= target && nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else{
                if(nums[r] == nums[mid])
                    ++l , --r;
                else
                    ++l;
            }
        }
        return false;
    }
};
