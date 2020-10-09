// https://leetcode.com/problems/roman-to-integer/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0, n = s.size();
        unordered_map<char, int> roman = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int temp = roman[s[n - 1]];
        ans += roman[s[n - 1]];
        
        for(int i = n - 1; i > 0; --i){
            if(temp <= roman[s[i - 1]]){
                temp = roman[s[i - 1]];
                ans += temp;
            }
            else{
                ans -= roman[s[i - 1]];
            }
        }
        return ans;
    }
};
