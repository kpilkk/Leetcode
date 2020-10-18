// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// Backtracking solution
class Solution {
    vector<string> phone = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length() != 0)
            backtrack("", digits);
        return ans;
    }
    
    void backtrack(string combination, string next_digits){
        if(next_digits.length() == 0)
            ans.push_back(combination);
        else{
            string letters = phone[next_digits[0] - '0'];
            for(int i = 0; i < letters.length(); ++i){
                string letter = letters.substr(i, 1);
                backtrack(combination + letter, next_digits.substr(1));
            }
        }
    }
};

// Iterative BFS solution using queue
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> phone = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.empty())
            return {};
        
        queue<string> q;
        vector<string> ans;
        
        q.push("");

        while(!q.empty()){
            string s = q.front();
            q.pop();
            
            if(s.length() == digits.length())
                ans.push_back(s);
            else{
                string temp = phone[digits[s.length()] - '0'];
                for(auto i : temp)
                    q.push(s + i);
            }
        }
        return ans;
    }
};
