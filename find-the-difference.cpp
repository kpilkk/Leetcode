// https://leetcode.com/problems/find-the-difference/

// solution using xor
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0;
        for(char c : s) ans ^= c;
        for(char c : t) ans ^= c;
        return ans;
    }
};
