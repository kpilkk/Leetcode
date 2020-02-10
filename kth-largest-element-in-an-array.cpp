// https://leetcode.com/problems/kth-largest-element-in-an-array/
/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5

Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        // if(n==0 || n==1) return num
        for(int i=0;i<k;++i){
            for(int j=0;j<n-i-1;++j)
                if(nums[j]>nums[j+1])
                    swap(nums[j],nums[j+1]);
        }
        return nums[n-k];
    }
};
