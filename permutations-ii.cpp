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
private:
    void nextPermutation(vector<int>& nums){
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if(i >= 0){
            int j = nums.size() - 1;
            for(; j >= 0; --j){
                if(nums[j] > nums[i])
                    break;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return {{}};
        vector<vector<int>> ans;
        vector<int> dummy(nums);

        do {
            ans.push_back(nums);
            nextPermutation(nums);
        } while(nums != dummy);
        return ans;
    }
};
