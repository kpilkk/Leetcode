// https://leetcode.com/problems/implement-strstr/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        int m = haystack.length(), n = needle.length();
        if(m == 0)
            return -1;
        for(int i = 0; i < m; ++i){
            if(haystack[i] != needle[0])
                continue;
            else{
                int j = i, k = 0;
                while(k < n && j < m){
                    if(haystack[j] != needle[k]){
                        break;
                    }
                    else{
                        ++j, ++k;
                    }
                }
                if(k == n)
                    return i;
            }
        }
        return -1;
    }
};
