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

// Using k-Sum - more generalized solution
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k){
        vector<vector<int>> res;
        if(start == nums.size() || nums[start] * k > target || target > nums.back() * k)
            return res;
        if(k == 2)
            return twoSum(nums, target, start);
        for(int i = start; i < nums.size(); ++i)
            if(i == start || nums[i - 1] != nums[i])
                for(auto set : kSum(nums, target - nums[i], i + 1, k - 1)){
                    res.push_back({nums[i]});
                    res.back().insert(end(res.back()), begin(set), end(set));
                }
        return res;
    }
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start){
        vector<vector<int>> res;
        int l = start, r = nums.size() - 1;
        while(l < r){
            int sum = nums[l] + nums[r];
            if(sum < target || (l > start && nums[l] == nums[l - 1]))
                ++l;
            else if(sum > target || (r < nums.size() - 1 && nums[r] == nums[r + 1]))
                --r;
            else
                res.push_back({nums[l++], nums[r--]});
        }
        return res;
    }
};
