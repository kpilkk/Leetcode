// https://leetcode.com/problems/longest-palindromic-substring/

// Brute Force : TLE

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans;
        int len = 1;
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(isPallindrome(s, i, j)){
                    if(len <= j - i + 1){
                        len = j - i + 1;
                        ans = s.substr(i, len);
                    }
                }
            }
        }
        return ans;
    }
private:
    bool isPallindrome(string s, int i, int j){
        while(i <= j)
            if(s[i++] != s[j--])
                return false;
        return true;
    }
};
