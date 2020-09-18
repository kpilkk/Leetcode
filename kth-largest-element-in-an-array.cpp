// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < k; ++i)
            for(int j = 1; j < n - i; ++j)
                if(nums[j - 1] > nums[j])
                    swap(nums[j - 1], nums[j]);
        return nums[n - k];
    }
};

// Using sorting

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// Blum-Floyd-Pratt-Rivest-Tarjan algorithm
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return kthSmallest(nums, 0, nums.size() - 1, nums.size() - k + 1);
    }
    
    int kthSmallest(vector<int>& nums, int l, int r, int k){
        if(k > 0 && k <= r - l + 1){
            int n = r - l + 1;
            int i;
            // divided into 5 parts and found out their median
            vector<int> median((n + 4) / 5);
            for(i = 0; i < n / 5; ++i)
                median[i] = findMedian(nums, l + i * 5, 5); // median of 5 elements
            if(i * 5 < n)
                median[i++] = findMedian(nums, l + i * 5, n % 5);
            
            int medOfMedian = i == 1 ? median[0] : kthSmallest(median, 0, i - 1, i / 2);
            
            int pos = partition(nums, l, r, medOfMedian);
            
            if(pos - l == k - 1) 
                return nums[pos];
            if(pos - l > k - 1) 
                return kthSmallest(nums, l, pos - 1, k);
            return kthSmallest(nums, pos + 1, r, k - pos + l - 1);
        }
        return numeric_limits<int>::min();
    }
    
    int findMedian(vector<int>& nums, int l, int r){
        sort(nums.begin() + l, nums.begin() + l + r);
        return nums[l + r / 2];
    }
    
    int partition(vector<int>& nums, int l, int r, int x){
        int i;
        for(i = l; i < r; ++i)
            if(nums[i] == x)
                break;
        swap(nums[i], nums[r]);
        i = l;
        for(int j = l; j <= r - 1; ++j){
            if(nums[j] <= x)
                swap(nums[i++], nums[j]);
        }
        swap(nums[i], nums[r]);
        return i;
    }
};
