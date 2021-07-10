// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

// Brute force time limit exceeded - O(n2)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums1.size();
        int n = nums2.size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                int k = 0;
                while(i + k < m && j + k < n && nums1[i + k] == nums2[j + k])
                    k += 1;
                ans = max(ans, k);
            }
        return ans;
    }
};

// DP with space not optimized
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums1.size(), n = nums2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans;
    }
};