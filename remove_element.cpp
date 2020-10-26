// https://leetcode.com/problems/remove-element/

// 1st solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n==0) return n;
        
        int j = 0;
        for(int i=0;i<n;++i){
            if(nums[i]!=val){
               nums[j++] = nums[i]; 
            }
        }
        return j;
    }
};

// 2nd solution
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = 0;
        while(i < n){
            while(i < n && nums[i] == val)
                ++i;
            if(i < n)
                nums[j++] = nums[i++];
        }
        return j;
    }
};
