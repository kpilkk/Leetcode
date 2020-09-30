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


// Manacher's algorithm
class Solution {
public:
    string longestPalindrome(string s) {
        string ss = "$";
        for (char c : s) {
            ss += "#";
            ss += c;
        }
        ss += "#";
        vector<int> Len(ss.size(), 0);
        int pivot = 0, mx = 0;
        for (int i = 1; i < ss.size(); ++i) {
            if (i < mx) Len[i] = min(mx - i, Len[2 * pivot - i]);
            else Len[i] = 1;
            while (ss[i + Len[i]] == ss[i - Len[i]]) ++Len[i];
            if (i + Len[i] >= mx) {
                mx = i + Len[i];
                pivot = i;
            }
        }
        int start = max_element(Len.begin(), Len.end()) - Len.begin();
        return s.substr((start - Len[start]) / 2, Len[start] - 1);
    }
};
