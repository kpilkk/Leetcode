// https://leetcode.com/problems/implement-strstr/

// fastest
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        
        string kmp = needle + "#" + haystack;
        
        int m = kmp.size(), n = needle.size();
        
        vector<int> lps(m , 0);
        
        for(int i = 1, len = 0; i < m;){
            if(kmp[i] == kmp[len]){
                lps[i] = ++len;
                if(len == n)
                    return i - 2 * n;
                ++i;
            }
            else if(len == 0)
                lps[i++] = 0;
            else
                len = lps[len - 1];
        }
        return -1;
    }
};

// Brute forcc
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

// KMP algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();
        if(!n)
            return 0;
        vector<int> lps = kmpProcess(needle);
        for(int i = 0, j = 0; i < m;){
            if(haystack[i] == needle[j])
                ++i, ++j;
            if(j == n)
                return i - j;
            if(i < m && haystack[i] != needle[j])
                j ? j = lps[j - 1] : i++;
        }
        return -1;
    }

private:
    vector<int> kmpProcess(string needle){
        int n = needle.size();
        vector<int> lps(n , 0);
        for(int i = 1, len = 0; i < n;){
            if(needle[i] == needle[len])
                lps[i++] = ++len;
            else if(len)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
        return lps;
    }
};
