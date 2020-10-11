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

// Vertical Scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        for(int i = 0; i < strs[0].length(); ++i){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); ++j)
                if(i == strs[j].length() || strs[j][i] != c)
                    return strs[0].substr(0 , i);
        }
        return strs[0];
    }
};
