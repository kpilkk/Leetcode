// https://leetcode.com/problems/rotate-array/

// Juggling algorithm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        int g = gcd(k, n);
        
        for(int i = 0; i < g; ++i){
            int temp = nums[i];
            int j = i;
            
            while(1){
                int d = (j + n - k) % n;
                if(d == i)
                    break;
                
                nums[j] = nums[d];
                j = d;
            }
            nums[j] = temp;
        }
    }
};

// reverse algorithm
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

