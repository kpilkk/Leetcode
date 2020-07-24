// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return -1;
        
        int low = 0, high = n-1;
        while(nums[low]>nums[high]){
            int mid = low+(high-low)/2;
            if(nums[mid]>=nums[low])
                low = mid+1;
            else if(nums[mid]<nums[high])
                high = mid;
        }
        return nums[low];
    }
};
