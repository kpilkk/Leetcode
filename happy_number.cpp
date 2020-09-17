// https://leetcode.com/problems/happy-number/

// 1st solution using Floyd-cycle algorithm
class Solution {
public:
    int square_of_digits(int num){
        int sum = 0, temp;
        while(num){
            temp = num % 10;
            sum += temp*temp;
            num/=10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        if(n==0) return false;
        if(n==1) return true;
        
        int slow = n, fast = n;
        
        // cout << slow << " " << fast << endl;
        do{
            slow = square_of_digits(slow);
            fast = square_of_digits(fast);
            fast = square_of_digits(fast);
        }while(slow!=fast);
        
        if(slow == 1) return 1;
        return 0;
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
