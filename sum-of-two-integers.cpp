// https://leetcode.com/problems/sum-of-two-integers/

/* 
    Following error if carry is not converted to unsigned int
    runtime error: left shift of negative value -2147483648 (solution.cpp)
    SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.
*/
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = a & b;
            a ^= b;
            b = (unsigned int)carry << 1;
        }
        return a;
    }
};
