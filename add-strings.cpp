// https://leetcode.com/problems/add-strings/

class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string ans(max(m, n), '0');
        int si = ans.size() - 1;
        int i = m - 1, j = n - 1, carry = 0;
    
        while(i >= 0 && j >=0){
            int sum = (num1[i--] - '0') + (num2[j--] - '0') + carry;
            ans[si--] = (sum % 10) + '0';
            carry = sum / 10;
        }
        
        while(i >= 0){
            int sum = (num1[i--] - '0') + carry;
            ans[si--] = (sum % 10) + '0';
            carry = sum / 10;
        }
        
        while(j >= 0){
            int sum = (num2[j--] - '0') + carry;
            ans[si--] = (sum % 10) + '0';
            carry = sum / 10;
        }
        
        if(carry)
            ans.insert(ans.begin(), carry + '0');
        
        return ans;
    }
};
