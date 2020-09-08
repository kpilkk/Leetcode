// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m =  nums1.size();
        int n = nums2.size();
        int target = (m + n);
        int i = 0, j = 0, count = 0, prev = 0;
        
        while(true) {
            int ans = 0;
            
            int x = INT_MAX;
            int y = INT_MAX;
            
            if(i < nums1.size()) x = nums1[i];
            if(j < nums2.size()) y = nums2[j];
            
            if(x == INT_MAX && y == INT_MAX) break;
            
            if(x < y) {
                ans = x;
                i++;
            }
            else {
                ans = y;
                j++;
            }
            
            if(count == target / 2) {
                if(target % 2 != 0) {
                    return ans;
                }
                else {
                    return (double)(prev + ans) / 2;
                }
            }
            prev = ans;
            count++;
        }
        return 0;
    }
};
