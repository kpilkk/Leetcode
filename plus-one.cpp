// https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        int sum = digits[n-1] + 1;
        digits[n - 1] = sum % 10;
        int carry = sum / 10;
        
        int i = n - 2;
        while(carry != 0 && i >= 0){
            sum = digits[i] + carry;
            digits[i--] = sum % 10;
            carry = sum / 10;
        }
        if(carry)
            digits.emplace(digits.begin(), carry);
        
        return digits;
    }
};
