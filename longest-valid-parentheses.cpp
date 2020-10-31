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
