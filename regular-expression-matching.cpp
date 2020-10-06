// https://leetcode.com/problems/regular-expression-matching/

// Recursive solution
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        bool first_match = !s.empty() && ((p[0] == s[0]) || p[0] == '.');
        
        /* The most critical observation is that "x*" can either match empty string, 
        or at least one x. In the latter case, it is equivalent to "xx*" or "x*x"*/
        if(p[1] == '*'){
            return (isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p)));
        }
        else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// DP solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        if(n >= 1 && p[0] == '*') return 0;
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i)
            dp[i][0] = false;
        for(int j = 1; j <= n; ++j)
            dp[0][j] = j > 1 && p[j - 1] == '*' && dp[0][j - 2];
        
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j - 1] != '*')
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                else
                    dp[i][j] = dp[i][j - 2] || ((s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            }
        }
        return dp[m][n];
    }
};
