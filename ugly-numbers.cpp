// https://leetcode.com/problems/ugly-number/

class Solution {
public:
    bool isUgly(int num) {
        if(num < 1) return 0;
        while(!(num % 2))
            num /= 2;
        while(!(num % 3))
            num /= 3;
        while(!(num % 5))
            num /= 5;
        return num == 1 ? 1 : 0;
    }
};
