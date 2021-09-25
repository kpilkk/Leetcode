// https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;++i){
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
        }
        
        for(int i=0;i<n;++i){
            if(nums[i]!=i+1) return i+1;
        }
        return n+1;
    }
};


// 2nd solution from GFG

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool one = false;
        int n = nums.size();
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                one = true;
                break;
            }
        }
        
        if(!one)
            return 1;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            nums[(nums[i] - 1) % n] += n;
        }
        
        for(int i = 0; i < n; ++i)
            if(nums[i] <= n)
                return i + 1;
        
        return n + 1;
    }
};