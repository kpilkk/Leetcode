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
        while(n > 0){
            f *= n--;
        }
        return f;
    }
    
    void nextPermutation(vector<int>& nums){
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        
        if(i >= 0){
            int j = nums.size() - 1;
            for(; j >= 0; --j)
                if(nums[j] > nums[i])
                    break;
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        int size = factorial(n);

        ans.push_back(nums);
        for(int i = 1; i < size; ++i){
            nextPermutation(nums);
            ans.push_back(nums);
        }
        return ans;
    }
};
