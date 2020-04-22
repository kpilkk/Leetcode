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
