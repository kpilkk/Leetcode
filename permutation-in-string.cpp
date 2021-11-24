// https://leetcode.com/problems/permutation-in-string/

class Solution {
    static bool allZero(const int count[]){
        for(int i = 0; i < 26; ++i){
            if(count[i] != 0)
                return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int i = 0;
        int n = s1.size();
        int j = n;
        
        int count[26] = {0};
        
        for(int k = 0; k < n; ++k){
                count[s1[k]-'a']++;
        }
        
        while(j <= s2.size()){
            for(int k = i; k < j; ++k){
                count[s2[k]-'a']--;
            }
            
            if(allZero(count))
                return true;
            
            for(int k = i; k < j; ++k){
                count[s2[k]-'a']++;
            }
            ++i, ++j;
        }
        
        return false;
    }
};