// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int si = m + n;
        
        int even = 0, mid;
        if(si % 2 == 0){
            even = 1;
            mid = si / 2;
        }
        else{
            mid = si / 2 + 1;
        }
        
        int i = 0, j = 0, k = 0, ans = 0;
        while(k < mid && i < m && j < n){
            if(nums1[i] <= nums2[j]){
                ans = nums1[i++];
            }
            else{
                ans = nums2[j++];
            }
            k++;
        }
        
        while(k < mid){
            if(i < m){
                ans = nums1[i++];
            }
            else{
                ans = nums2[j++];
            }            
            k++;
        }
        
        if(!even)
            return (double)ans;
        else{
            double x = ans, y;
            if(i < m && j == n){
                y = nums1[i];
            }
            else if(j < n && i == m)
                y = nums2[j];
            else if(nums1[i] <= nums2[j])
                y = nums1[i];
            else
                y = nums2[j];
            
            return (x + y) / 2;
        }
    }
};
