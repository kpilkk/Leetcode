// https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        // if(n==0) return;
        int j = 0;
        for(int i=0;i<n;++i){
            if(nums[i]!=0){
                nums[j++] = nums[i];
            }
        }
        for(int i=j;i<n;++i)
            nums[i] = 0;
    }
};

// Easy two pointer solution
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        
        while(i < nums.size()){
            if(nums[i] != 0){
                swap(nums[i], nums[j++]);
            }
            ++i;
        }
    }
};