// https://leetcode.com/problems/string-to-integer-atoi/submissions/

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        
        int i = 0;
        while(i < n && str[i] == ' ')
            ++i;
        
        int sign = 1;
        if(i < n && (str[i] == '+' || str[i] == '-'))
            sign = (str[i++] == '-') ? -1 : 1;
        
        int result = 0;
        while(i < n && str[i] >= '0' && str[i] <= '9'){
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            result = result * 10 + (str[i++] - '0');
        }
        
        return result * sign;
    }
};
