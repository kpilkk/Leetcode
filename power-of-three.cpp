// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        
        double x = log10(n) / log10(3);
        
        return ceil(x)==floor(x);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
      return n < 1 ? false : !(1162261467 % n);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
      if (n<1) return false;

      while(n!=1){
        if (n%3 != 0) return false;
        n /= 3;
      }

      return true;
    }
};
