// https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] < nums2[j])
                nums1[k--] = nums2[j--];
            else
                nums1[k--] = nums1[i--];
        }
        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
};

// Problem description - https://www.geeksforgeeks.org/merge-two-sorted-arrays/
// Using gap method
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
            int gap = ceil((float)(m + n)/ 2);
            //int i = 0;
            
            while(gap > 0){
                int i = 0;
                int j = gap;
                while(j < m + n){
                    if(j < n && arr1[i] > arr1[j]){
                        swap(arr1[i], arr1[j]);
                    }
                    else if(j >= n && i < n && arr1[i] > arr2[j - n]){
                        swap(arr1[i], arr2[j - n]);
                    }
                    else if(j >= n && i >= n && arr2[i - n] > arr2[j - n]){
                        swap(arr2[i - n], arr2[j - n]);
                    }
                    ++i;
                    ++j;
                }
                if(gap == 1)
                    gap = 0;
                else
                    gap = ceil((float)gap /2);
            }
        } 
};