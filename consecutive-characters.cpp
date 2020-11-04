// https://leetcode.com/problems/consecutive-characters/

class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        // if(n == 1)
        //     return 1;
        int ans = 1, i = 0;
        while(i < n){
            int temp = i;
            while(i < n - 1 && s[i] == s[i + 1])
                ++i;
            ans = max(ans, i - temp + 1);
            ++i;
        }
        return ans;
    }
};
