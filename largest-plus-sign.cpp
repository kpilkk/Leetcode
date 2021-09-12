// https://leetcode.com/problems/largest-plus-sign/

class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int ans = 0;
        
        vector<vector<int>> dp(n, vector<int>(n, 1));
        
        for(int i = 0; i < mines.size(); ++i)
            dp[mines[i][0]][mines[i][1]] = 0;
        
        vector<vector<int>> left, right, top, bottom;
        left = right = top = bottom = dp;
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int x = n - 1 - i;
                int y = n - 1 - j;
                if(i > 0 && top[i][j])
                    top[i][j] += top[i - 1][j];
                if(j > 0 && left[i][j])
                    left[i][j] += left[i][j - 1];
                if(x < n - 1 && bottom[x][y])
                    bottom[x][y] += bottom[x + 1][y];
                if(y < n - 1 && right[x][y])
                    right[x][y] += right[x][y + 1];
            }
        }
        
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                ans = max(ans, min({left[i][j], right[i][j], top[i][j], bottom[i][j]}));
        
        return ans;
    }
};