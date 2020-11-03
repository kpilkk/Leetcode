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

// 2nd solution
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = n - 1;
        vector<int> res(2, -1);
        if(n == 0)
            return res;
        // search for the left one
        while(i < j){
            int mid = (i + j) / 2;
            if(nums[mid] < target)
                i = mid + 1;
            else
                j = mid;
        }
        if(nums[i] != target)
            return res;
        else
            res[0] = i;
        
        // search for the right one
        j = n - 1;  // we don't have to set i to 0 the second time
        while(i < j){
            int mid = (i + j) / 2 + 1;  // make mid biased to the right
            if(nums[mid] > target)
                j = mid - 1;
            else
                i = mid;    // so that this won't make the search range stuck
        }
        res[1] = j;
        return res;
    }
};
