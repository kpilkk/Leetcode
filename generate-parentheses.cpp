// https://leetcode.com/problems/generate-parentheses/

// Backtracking solution
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, "", 0, 0, n);
        return ans;
    }
    
    void backtrack(vector<string>& ans, string cur, int open, int close, int max){
        if(cur.length() == max * 2){
            ans.push_back(cur);
            return;
        }
        
        if(open < max)
            backtrack(ans, cur + "(", open + 1, close, max);
        if(close < open)
            backtrack(ans, cur + ")", open, close + 1, max);
    }
};


// Closure Number
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(!n)
            return {""};
        
        vector<string> ans;
        for(int i = 0; i < n; ++i){
            for(string l : generateParenthesis(i)){
                for(string r : generateParenthesis(n  - 1 - i)){
                    ans.push_back('(' + l + ')' + r);
                }
            }
        }
        
        return ans;
    }
};