// https://leetcode.com/problems/unique-paths/

// Using DP
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Same as above with memory optimizaion
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

// Using Maths
class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;
        int tot = m + n - 2;
        int mini = min(m - 1, n - 1);
        for(int i = 0; i < mini; ++i){
            ans *= (tot - i);
        }
        for(int i = 0; i < mini; ++i){
            ans /= (mini - i);
        }
        
        return ans;
    }
};
