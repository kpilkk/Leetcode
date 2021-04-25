// https://leetcode.com/problems/combination-sum/
// backtracking solution

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        combination(result, 0, 0, temp, candidates, target);
        return result;
    }
    
    void combination(vector<vector<int>>& result, int idx, int sum, vector<int>& temp, vector<int>& candidates, int target){
        if(sum > target)
            return;
        if(sum == target){
            result.emplace_back(temp);
            return;
        }
        for(int i = idx; i < candidates.size(); ++i){
            temp.emplace_back(candidates[i]);
            combination(result, i , sum + candidates[i], temp, candidates, target);
            temp.pop_back();
        }
    }
};
