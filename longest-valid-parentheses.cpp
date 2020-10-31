// https://leetcode.com/problems/longest-valid-parentheses/

// Brute force : TLE
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        for(int i = 0; i < s.length(); ++i)
            for(int j = i + 2; j <= s.length(); j += 2)
                if(isValid(s.substr(i, j - i)))
                    maxLen = max(maxLen, j - i);

        return maxLen;
    }
    
    bool isValid(string s){
        stack<char> temp;
        for(int i = 0; i < s.length(); ++i){
            if(s[i] == '(')
                temp.push(s[i]);
            else if(!temp.empty() && temp.top() == '(')
                temp.pop();
            else
                return false;
        }
        return temp.empty();
    }
};

// DP solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int ans = 0;
        
        vector<int> dp(n , 0);
        for(int i = 1; i < n; ++i){
            if(s[i] == ')'){
                if(s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

// Using stack
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0, n = s.length();
        stack<int> temp;
        temp.push(-1);
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                temp.push(i);
            else{
                temp.pop();
                if(temp.empty())
                    temp.push(i);
                else
                    ans = max(ans, i - temp.top());
            }
        }
        return ans;
    }
};

// Without extra space
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, ans = 0, n = s.length();
        
        for(int i = 0; i < n; ++i){
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                ans = max(ans , 2 * right);
            else if(right > left)
                left = right = 0;
        }
        
        left = right = 0;
        
        for(int i = n - 1; i >= 0; --i){
            if(s[i] == '(')
                ++left;
            else
                ++right;
            if(left == right)
                ans = max(ans, 2 * right);
            else if(left > right)
                left = right = 0;
        }
        
        return ans;
    }
};
