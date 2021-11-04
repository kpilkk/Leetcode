// https://leetcode.com/problems/reverse-words-in-a-string-iii/

class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        int n = s.length();
        
        for(int i = 0; i <= n; ++i){
            if(i == n || s[i] == ' '){
                reverse(s.begin() + j, s.begin() + i);
                j = i + 1;
            }
        }
        return s;
    }
};