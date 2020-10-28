// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == dividend)
            return 1;
        
        if(dividend == INT_MIN){
            if(divisor == -1)
                return INT_MAX;
            else if(divisor == 1)
                return dividend;
            else
                return (divisor & 1) ? divide(dividend + 1, divisor) : divide(dividend >> 1, divisor >> 1);
        }
        
        if(divisor == INT_MIN)
            return 0;
        
        int sign = (dividend < 0) ^ (divisor < 0) ? 1 : 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        int ans = 0;

        while(dividend >= divisor){
            unsigned int temp = divisor;
            int m = 1;
            while(temp << 1 <= dividend){
                temp <<= 1;
                m <<= 1;
            }
            dividend -= temp;
            ans += m;
        }
        
        if(sign)
            return -ans;
        return ans;
    }
};
