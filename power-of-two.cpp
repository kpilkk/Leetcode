// https://leetcode.com/problems/power-of-two/

/*
    so in case a no is power of two then the only one bit must be set in its binary representation .
  -> remove the last set bit
  -> look if no becomes zero
  -> if zero then it must be having only one set bit ie - it must have been the power of 2
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(n<=0)    
        return false;
      n -= (n&-n);
      return n==0;
    }
};


class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
    }
};
