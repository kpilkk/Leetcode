// https://leetcode.com/problems/longest-common-prefix/

// Horizontal Scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";
        string ans = strs[0];
        for(int i = 1; i < n; ++i){
            while(strs[i].find(ans) != 0)
                ans = ans.substr(0, ans.length() - 1);
            if(ans.empty())
                return "";
        }
        return ans;
    }
};
