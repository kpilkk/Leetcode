// problem link : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

// 1st solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        while(i < n){
            while(i < n - 1 && nums[i] == nums[i + 1])
                ++i;
            nums[j++] = nums[i++];
        }
        return j;
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
