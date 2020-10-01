// https://leetcode.com/problems/zigzag-conversion/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> temp(numRows);
        int i = 0;
        int n = s.length();
        while(i < n){
            for(int j = 0; j < numRows && i < n; ++j){
                temp[j].push_back(s[i++]);
            }
            for(int j = numRows - 2; j > 0 && i < n; --j){
                temp[j].push_back(s[i++]);
            }
        }
        string ans;
        for(int i = 0; i < numRows; ++i){
            ans += temp[i];
        }
        return ans;
    }
};
