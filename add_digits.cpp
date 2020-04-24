// https://leetcode.com/problems/add-digits/

// my solution

class Solution {
public:
    static int sum_of_digits(int n){
        int sum = 0, temp;
        while(n){
            temp = n % 10;
            sum += temp;
            n /= 10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>9){
            num = sum_of_digits(num);
        }
        return num;
    }
};

// solution using digital root

class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        if(num%9 == 0) return 9;
        return num%9;
        /*
        dr(n) = 0 if n == 0 ,
        dr(n) = (b-1) if n != 0 and n % (b-1) == 0,
        dr(n) = n mod (b-1) if n % (b-1) != 0
        is equal to
        dr(n) = 1 + (n - 1) % 9.
        */
    }
};
