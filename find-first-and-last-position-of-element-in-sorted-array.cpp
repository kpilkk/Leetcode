// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> ans;
        
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                int temp = mid;
                while(mid > 0 && nums[mid] == nums[mid - 1])
                    --mid;
                ans.emplace_back(mid);
                while(temp < n - 1 && nums[temp] == nums[temp + 1])
                    ++temp;
                ans.emplace_back(temp);
                return ans;
            }
            if(nums[mid] < target)
                l = mid + 1;
            else if(nums[mid] > target)
                r = mid - 1;
        }
        return {-1 , -1};
    }
};
