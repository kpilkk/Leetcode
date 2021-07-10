// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

// Brute force time limit exceeded - O(n2)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int m = nums1.size();
        int n = nums2.size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j){
                int k = 0;
                while(i + k < m && j + k < n && nums1[i + k] == nums2[j + k])
                    k += 1;
                ans = max(ans, k);
            }
        return ans;
    }
};
