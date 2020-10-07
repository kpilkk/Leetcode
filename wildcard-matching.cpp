// https://leetcode.com/problems/wildcard-matching/

// Brute Force : TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty())
            return s.empty();
        else if(s.empty())
            return p[0] == '*' && isMatch(s, p.substr(1));
        else if(p[0] == '*')
            return isMatch(s, p.substr(1)) || isMatch(s.substr(1), p);
        else if(p[0] == '?' || p[0] == s[0])
            return isMatch(s.substr(1), p.substr(1));
        else
            return false;
    }
};

// DP solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
            
        for(int i = 0; i <= m; ++i){
            for(int j = 0; j <= n; ++j){
                if(i == 0 && j == 0)
                    dp[i][j] = true;
                else if(i == 0)
                    dp[i][j] = p[j - 1] == '*' && dp[i][j - 1];
                else if(j == 0)
                    dp[i][j] = false;
                else if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j]; 
                else
                    dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || p[j - 1] == s[i - 1]);
            }
        }
        return dp[m][n];
    }
};

// O(n) solution
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        int i = 0, j = 0;
        int iIndex = -1, jIndex = -1;
        
        while(i < m){
            if(s[i] == p[j] || (j < n && p[j] == '?')){
                ++i;
                ++j;
            }
            else if(j < n && p[j] == '*'){
                jIndex = j;
                iIndex = i;
                ++j;
            }
            else if(jIndex != -1){
                j = jIndex + 1;
                i = iIndex + 1;
                iIndex++;
            }  
            else
                return 0;
        }
        
        while(j < n && p[j] == '*')
            ++j;
        
        return j == n ? 1 : 0;
    }
};
