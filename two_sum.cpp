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
        map<int, int> s;
        vector<int> ans;
        int i;
        for(i=0;i<nums.size();++i){
            int complement = target - nums[i];
            if(s.find(complement)!=s.end()){
                ans.push_back(s[complement]);
                ans.push_back(i);
                break;
            }
            else
                s.insert(make_pair(nums[i], i));
        }
        return ans;
    }
};
