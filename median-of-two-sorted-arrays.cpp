// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>

using namespace std;

// Merge sort
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        int curr = -1, prev = -1;
        int i = 0, j = 0;
        for (int count = 0; count <= (m + n) / 2; ++count)
        {
            prev = curr;

            if (i != m && j != n)
            {
                curr = nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
            }
            else if (i < m)
            {
                curr = nums1[i++];
            }
            else
            {
                curr = nums2[j++];
            }
        }

        if ((m + n) % 2)
        {
            return curr;
        }
        return (curr + prev) / 2.0;
    }
};

// Recursive Binary Search
class Solution
{
private:
    int findMedian(vector<int> &nums1, vector<int> &nums2, int k, int nums1Start, int nums2Start, int m, int n)
    {
        if (nums1Start > m)
        {
            return nums2[k - nums1Start];
        }
        if (nums2Start > n)
        {
            return nums1[k - nums2Start];
        }

        int nums1Index = (nums1Start + m) / 2;
        int nums2Index = (nums2Start + n) / 2;
        int nums1Value = nums1[nums1Index];
        int nums2Value = nums2[nums2Index];

        if (nums1Index + nums2Index < k)
        {
            if (nums1Value < nums2Value)
                return findMedian(nums1, nums2, k, nums1Index + 1, nums2Start, m, n);
            else
                return findMedian(nums1, nums2, k, nums1Start, nums2Index + 1, m, n);
        }
        else
        {
            if (nums1Value < nums2Value)
                return findMedian(nums1, nums2, k, nums1Start, nums2Start, m, nums2Index - 1);
            else
                return findMedian(nums1, nums2, k, nums1Start, nums2Start, nums1Index - 1, n);
        }
        return -1;
    }

public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();

        int k = (m + n) / 2;

        if ((m + n) % 2)
        {
            return findMedian(nums1, nums2, k, 0, 0, m - 1, n - 1);
        }
        return (findMedian(nums1, nums2, k, 0, 0, m - 1, n - 1) + findMedian(nums1, nums2, k - 1, 0, 0, m - 1, n - 1)) / 2.0;
    }
};