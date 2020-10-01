// https://leetcode.com/problems/reverse-integer/

class Solution {
public:
    int reverse(int x) {
        bool sign = x >= 0 ? 1 : 0;
        long temp;
        // converting negative numbers to positive number
        if(!sign)
            temp = -(long)x;   // typecasting before negating as It'll overflow for INT_MAX
        else
            temp = x;
        
        temp = rev(temp);
        
        // changing the signs as required
        if(!sign)
            temp = -temp;
        
        // see if reversing the array overflows
        if(temp >= INT_MIN && temp <= INT_MAX)
            return temp;
        return 0;
    }
private:
    // function to reverse an integer
    long rev(long x){
        long rev = 0;
        while(x){
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
};

// Using string reverse
class Solution {
public:
    int reverse(int x) {
        bool sign = x >= 0 ? 1 : 0;
		
        long temp;
        if(!sign)
            temp = -(long)x;
        else
            temp = x;
        
        temp = rev(temp);
        if(!sign)
            temp = -temp;
			
        if(temp >= INT_MIN && temp <= INT_MAX)
            return temp;
        return 0;
    }
private:
    long rev(long x){
        string temp = to_string(x);
		    // ::reverse is used to call string reverse function
        ::reverse(temp.begin(), temp.end());
        return stol(temp);
    }
};
