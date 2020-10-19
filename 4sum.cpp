// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 4) return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; ++i){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            if(nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if(nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            for(int j = i + 1; j < n - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if(nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if(nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target)
                    continue;
                int l = j + 1;
                int r = n - 1;
                while(l < r){
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if(sum < target)
                        ++l;
                    else if(sum > target)
                        --r;
                    else{
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        do{
                            ++l;
                        } while(l < r && nums[l] == nums[l - 1]);
                        do{
                            --r;
                        } while(r > l && nums[r] == nums[r + 1]);
                    }
                }
            }
        }
        return ans;
    }
};
