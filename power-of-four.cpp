// https://leetcode.com/problems/power-of-four/

// Brute force
class Solution {
public:
    bool isPowerOfFour(int num) {
        while(num > 1) {
            if(num % 4)return false;
            num /= 4;
        }
        return num == 1;
    }
};

/*
    Conditions for a number to be the power of four
    1. No of Set Bit Always Be Only ONE 
    2. That SetBit Possition Should Be always In odd Place [ starting from Left ]
*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<0)return false;
        int no_of_one = 0,pos = 1,ones_pos = 0;
        while(num){
            if(num&1)no_of_one+=1,one_pos = pos;
            num>>=1,pos+=1;
        }
        return no_of_one==1 && one_pos&1;
    }
};

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
        return (num>0) && (!(num-1)&num)==0 && (num-1)%3==0;
    }
};
