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
        // Insert another 2 different special characters in the front and the end of string s to avoid bound checking.
        string manacher_str = "@#";
        for (int i = 0; i < s.size(); i++)
            manacher_str = manacher_str + s[i] + "#";
        manacher_str += "$";
        
        int len = manacher_str.size();
        vector<int> RL(len, 0);
        
        int c = 0, r = 0;    // current center, right limit
        int maxLen = 0, maxLenPos = 0;  //maxLen
        
        for (int i = 1; i < len - 1; i++) {
            // find the corresponding letter in the palidrome subString
            int iMirror = 2 * c - i;
            if (r > i)
                RL[i] = min(RL[iMirror], r - i);

            // Let d = distance r - i`, so expanding around i` center will start from (i` - d) - 1
            // with (i` + d) + 1 = (r + 1) and so on... 
            // because the interval is already contained in the palindrome with center 
            while (i - RL[i] >= 0 && i + RL[i] < len && manacher_str[i + RL[i] + 1] == manacher_str[i - RL[i] - 1])
                RL[i]++;

            if (RL[i] > maxLen) {
                maxLen = RL[i];
                maxLenPos = i;
            }

            // Update c, r in case if the palindrome centered at i expands past r
            if (i + RL[i] > r) {
                r = i + RL[i];
                c = i;
            }
        }
        
        return s.substr((maxLenPos - 1 - maxLen) / 2, maxLen);
        // s = "";
        // for (int i = maxLenPos - maxLen + 1; i < maxLenPos + maxLen - 1; i++)
        //     if (manacher_str[i] != '#')
        //         s += manacher_str[i];
        // return s;
    }
};
