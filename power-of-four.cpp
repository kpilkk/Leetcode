// https://leetcode.com/problems/power-of-four/

// Solution without any loops or recursion

class Solution {
public:
    bool isPowerOfFour(int num) {
        // code will fail for minimum value of integer i.e. It will underflow if (num>0) is not included below
        return ((num>0) && !(num&(num-1)) && (num&0x55555555));
    }
};

/* it's easy to find that power of 4 numbers have above 3 common features.
  First,greater than 0.Second,only have one '1' bit in their binary notation,
  so we use x&(x-1) to delete the lowest '1',and if then it becomes 0,
  it prove that there is only one '1' bit.Third,the only '1' bit should be 
  locate at the odd location,for example,16.It's binary is 00010000.
  So we can use '0x55555555' to check if the '1' bit is in the right place. 
*/

// 2nd solution 

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (n>0) && (!(num-1)&num)==0 && (num-1)%3==0;
    }
};
