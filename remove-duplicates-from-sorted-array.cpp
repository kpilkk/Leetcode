// problem link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// 1st solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if(nums.size()==0 || nums.size()==1)
        //     return nums.size();
        int i = 0;
        while(i<int(nums.size())-1){
            if(nums[i]==nums[i+1])
                nums.erase(nums.begin()+i);
            else
                ++i;
        }
        return nums.size();
    }
};

// 2nd solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int i = 0;
        for(int j=1;j<nums.size();++j){
            if(nums[i]!=nums[j]){
                ++i;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
