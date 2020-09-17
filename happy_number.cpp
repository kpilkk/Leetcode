// https://leetcode.com/problems/happy-number/

// 1st solution using Floyd-cycle algorithm
class Solution {
public:
    int squaredSum(int n){
        int sum = 0;
        while(n){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = squaredSum(n);
        while(slow != fast){
            slow = squaredSum(slow);
            fast = squaredSum(squaredSum(fast));
        }
        return fast == 1;
    }
};

// It can also be solved using hash-set or hash-map

class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.emplace(n);
        while(n != 1){
            int sum = 0;
            while(n){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            if(s.find(sum) == s.end())
                s.emplace(sum);
            else
                return false;
            n = sum;
        }
        return true;
    }
};
