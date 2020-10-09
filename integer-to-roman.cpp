// https://leetcode.com/problems/integer-to-roman/

// Easy solution
class Solution {
public:
    string intToRoman(int num) {
        vector<string> first  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        vector<string> second = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        vector<string> third  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        vector<string> fourth = {"", "M", "MM", "MMM"};
        
        string ans;
        while(num){
            if(num >= 1000){
                ans += fourth[num / 1000];
                num -= (num / 1000) * 1000; 
            }
            else if(num >= 100){
                ans += third[num / 100];
                num -= (num / 100) * 100; 
            }
            else if(num >= 10){
                ans += second[num / 10];
                num -= (num / 10) * 10; 
            }
            else{
                ans += first[num];
                num -= num; 
            }
        }
        return ans;
    }
};

// Compact for above solution
class Solution {
public:
    string intToRoman(int num) {
        vector<string> first  = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        vector<string> second = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        vector<string> third  = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        vector<string> fourth = {"", "M", "MM", "MMM"};
        
        return fourth[num / 1000] + third[(num % 1000) / 100] + second[(num % 100) / 10] + first[(num % 10)];
    }
};
