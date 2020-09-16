// https://leetcode.com/problems/single-number-iii/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0, n = nums.size();
        for(auto num : nums)
            temp ^= num;
        
        // to find the last set bit in mask
        int mask = temp & -temp;
        
        int num1 = 0, num2 = 0;
        // separating two types of numbers
        // one which has last bit set same as last bit set in mask
        // other bit unset
        for(auto num : nums){
            // below num & mask is kept in bracket due to == precedence over &
            if((num & mask) == 0)
                num1 ^= num;
            else
                num2 ^= num;
        }
        return {num1, num2};
    }
};
