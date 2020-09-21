class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return;
        int index=-1;
        for(int i=n-2;i>=0;--i){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }
        int large = index;
        if(index<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>index;--i){
                if(nums[index]<nums[i]){
                    large = i;
                    break;
                }
            }
            swap(nums[index],nums[large]);
            // cout << index << " "<<large;
            reverse(nums.begin()+index+1, nums.end());
        }
    }
};


// Consice solution

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;
        
        if(i >= 0){
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i])
                j--;
            swap(nums[j], nums[i]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};
