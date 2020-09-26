// https://leetcode.com/problems/longest-palindromic-substring/

// Brute Force : TLE : O(n3)

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

// O(n2) solution by expanding around centre

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() <= 1)
            return s;
        string longest = s.substr(0, 1);
        for(int i = 0; i < s.length(); ++i){
            string temp = expand(s , i , i);
            if(temp.length() >= longest.length())
                longest = temp;
            temp = expand(s, i, i + 1);
            if(temp.length() >= longest.length())
                longest = temp;
        }
        return longest;
    }
private:
    string expand(string s, int begin, int end){
        while(begin >= 0 && end <= s.length() - 1 && s[begin] == s[end])
            begin--, end++;
        return s.substr(begin + 1, end - begin - 1);
    }
};
