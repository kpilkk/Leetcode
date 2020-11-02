// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

// 1st solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) 
            return -1;
        
        int low = 0, high = n-1;
        while(nums[low] > nums[high]){
            int mid = low + (high - low) / 2;
            if(nums[mid] >= nums[low])
                low = mid + 1;
            else if(nums[mid] < nums[high])
                high = mid;
        }
        return nums[low];
    }
};

// 2nd solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        if(n == 1)
            return nums[0];
        if(nums[r] > nums[l])
            return nums[l];
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] < nums[mid - 1])
                return nums[mid];
            if(nums[mid] > nums[l])
                l = mid + 1;
            else
                r = mid;
        }
        return -1;
    }
};
