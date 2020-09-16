// https://leetcode.com/problems/missing-number/submissions/

// Solution is similar to first missing positive

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; ++i)
            while(nums[i] >= 0 && nums[i] < n && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        
        for(int i = 0; i < n; ++i)
            if(nums[i] != i)
                return i;
        
        return n;
    }
};

// Bit manipulation

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = nums.size();
        
        for(int i = 0; i < nums.size(); ++i)
            missing ^= i ^ nums[i];
        
        return missing;
    }
};
