// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return 0;
        
        if(x == reverse(x))
            return 1;
        return 0;
    }
private:
    int reverse(int x){
        int y = 0;
        while(x){
            if(y > INT_MAX / 10 || (y == INT_MAX / 10 && x % 10 > 7))  // when reverse of an integer overflows
                return -1;
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
};
