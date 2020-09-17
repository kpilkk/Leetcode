// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        for(int i=0;i<k;++i){
            for(int j=0;j<n-i-1;++j)
                if(nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
        }
        return nums[n-k];
    }
};

// Using sorting

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
