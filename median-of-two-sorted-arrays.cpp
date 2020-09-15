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


// Binary search method

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
            return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, r = m;
        
        while(l <= r){
            int i = (l + r) / 2, j = (m + n + 1) / 2 - i;
            if(i && nums1[i - 1] > nums2[j])
                // i is too big, must decrease it
                r = i - 1;
            else if(i < m && nums2[j - 1] > nums1[i])
                // i is too small, must increase it
                l = i + 1;
            else{
                // i is perfect
                int lmax = !i ? nums2[j - 1] : (!j ? nums1[i - 1] : max(nums1[i - 1], nums2[j - 1]));
                if((m + n) % 2)
                    return lmax;
                int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : min(nums1[i], nums2[j]));
                return 0.5 * (lmax + rmin);
            }
        }
        return 0.0;
    }
};
