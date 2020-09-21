// 1st solution using recursion

class Solution {
private:
    void permute(vector<int> nums, int i, vector<vector<int>>& ans){
        if(i==nums.size())
            ans.push_back(nums);
        else{
            for(int j=i;j<nums.size();++j){
                swap(nums[i],nums[j]);
                permute(nums, i+1, ans);
                // I've commented below swap because I'm not changing nums from original
                // Because I've not used address of the vector
                // swap(nums[i], nums[pos]);
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(nums, 0, ans);
        return ans;
    }
};

// Beside backtracking It can also be solved using Next permutation

// 2nd solution using Next permutation
class Solution {
private:
    int factorial(int n){
        int f = 1;
        while(n>1)
            f *= n--;
        return f;
    }
    void nextPermutation(vector<int>& nums){
        int n = nums.size(), index=-1, k;
        for(int i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        if(index<0)
            reverse(nums.begin(),nums.end());
        else{
            for(int j=n-1;j>index;--j){
                if(nums[j]>nums[index]){
                    k = j;
                    break;
                }
            }
            swap(nums[index], nums[k]);
            reverse(nums.begin()+index+1, nums.end());
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = factorial(nums.size());
        for(int i=0;i<n;++i){
            ans.push_back(nums);
            nextPermutation(nums);
        }
        return ans;
    }
};
