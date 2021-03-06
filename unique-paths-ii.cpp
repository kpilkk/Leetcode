// https://leetcode.com/problems/unique-paths-ii/

// DP solution
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 0; i < n; ++i){
            if(obstacleGrid[0][i] == 1){
                while(i < n){
                    dp[0][i++] = 0;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            if(obstacleGrid[i][0] == 1)
                while(i < m){
                    dp[i++][0] = 0;
                }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Modification of above but using no extra memory
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1)
            return 0;
        
        obstacleGrid[0][0] = 1;
            
        for(int i = 1; i < n; ++i)
            if(obstacleGrid[0][i] == 1)
                while(i < n)
                    obstacleGrid[0][i++] = 0;
            else
                obstacleGrid[0][i] = 1;
        
        for(int i = 1; i < m; ++i)
            if(obstacleGrid[i][0] == 1)
                while(i < m)
                    obstacleGrid[i++][0] = 0;
            else
                obstacleGrid[i][0] = 1;
        
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(obstacleGrid[i][j] == 1)
                    obstacleGrid[i][j] = 0;
                else
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
        
        return obstacleGrid[m - 1][n - 1];
    }
};
