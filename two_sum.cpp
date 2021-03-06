// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:

// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].

// Problem statement and reference
// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> temp;
        
        int n = nums.size();
        
        for(int i = 0; i < n; ++i){
            int complement = target - nums[i];
            if(temp.find(complement) != temp.end()){
                return {i, temp[complement]};
            }
            temp.insert(pair<int, int> (nums[i], i));
        }
        
        return {0, 0};
    }
};
