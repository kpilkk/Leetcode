/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

*/
// 1st solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        
        sort(nums.begin(), nums.end());
        int ans = 1;
        int count = 1;
        for(int i=0;i<n-1;++i){
            if(nums[i+1]-nums[i]==1)
                ++count;
            else if(nums[i+1]-nums[i]==0)
                continue;
            else{
                ans = max(count, ans);
                count = 1;
            }
        }
        ans = max(count, ans);
        return ans;
    }
};

//2nd solution
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int ans = 0;
        for(int num:nums){
            if(s.find(num-1)==s.end()){
                int cur = 1;
                while(s.find(num+cur)!=s.end())
                    ++cur;
                ans = max(cur, ans);
            }
        }
        return ans;
    }
};
