/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

// Solution using recursion

class Solution {
private:
    void permute(vector<int> nums, int i, vector<vector<int>>& ans){
        if(i==nums.size())
            ans.push_back(nums);
        else{
            for(int j=i;j<nums.size();++j){
                if(j==i || nums[j]!=nums[i]){
                    swap(nums[i],nums[j]);
                    permute(nums, i+1, ans);
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        permute(nums, 0, ans);
        return ans;
    }
};

// Solution using Next Permutation

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> perms;
        do {
            perms.push_back(nums);
        } while(nextPermutation(nums));
        return perms;
    }
private:
    bool nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, j;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                break;
            }
        }
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return false;
        } else {
            for (j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    break;
                }
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
            return true;
        }
    }
};
