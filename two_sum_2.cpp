// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        vector<int> ans;
        
        int l = 0, r = n - 1;
        
        while(l<r){
            if(numbers[l] + numbers[r] == target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            
            else if(numbers[l] + numbers[r] < target)
                l++;
            
            else
                r--;
        }
        return ans;
    }
};
