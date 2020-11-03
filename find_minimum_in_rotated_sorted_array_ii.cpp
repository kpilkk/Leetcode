// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

// 1st solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > nums[r]) {
                l = m + 1;
            } else if (nums[m] < nums[r]) {
                r = m;
            } else {
                r--;
            }
        }
        return nums[l];
    }
};

// 2nd solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r])
                l = mid + 1;
            else if(nums[mid] < nums[r])
                r = mid;
            else{
                if(nums[l] == nums[mid])
                    ++l, --r;
                else
                    r = mid;
            }
        }
        return nums[l];
    }
};

// 3rd solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right && nums[left]>=nums[right]){
            int mid=left+(right-left)/2;
            if(nums[mid]==nums[left]){
                ++left;
            }
            else if(nums[mid]<nums[left]){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return nums[left];
    }
};
