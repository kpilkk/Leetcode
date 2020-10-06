// https://leetcode.com/problems/wildcard-matching/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        
        int i = 0, j = 0;
        int iIndex = -1, jIndex = -1;
        
        while(i < m){
            if(s[i] == p[j] || (j < n && p[j] == '?')){
                ++i;
                ++j;
            }
            else if(j < n && p[j] == '*'){
                jIndex = j;
                iIndex = i;
                ++j;
            }
            else if(jIndex != -1){
                j = jIndex + 1;
                i = iIndex + 1;
                iIndex++;
            }  
            else
                return 0;
        }
        
        while(j < n && p[j] == '*')
            ++j;
        
        return j == n ? 1 : 0;
    }
};
