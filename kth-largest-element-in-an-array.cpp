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

// Using heap sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        buildMaxHeap(nums);
        for(int i = 0; i < k - 1; ++i){
            swap(nums[0], nums[--heapSize]);
            maxHeapify(nums, 0);
        }
        return nums[0];
    }
private:
    int heapSize;
    
    int left(int i){
        return (i << 1) + 1;
    }
    
    int right(int i){
        return (i << 1) + 2;
    }
    
    void maxHeapify(vector<int>& nums, int i){
        int largest = i, l = left(i), r = right(i);
        if(l < heapSize && nums[l] > nums[largest])
            largest = l;
        if(r < heapSize && nums[r] > nums[largest])
            largest = r;
        if(largest != i){
            swap(nums[i], nums[largest]);
            maxHeapify(nums, largest);
        }
    }
    
    void buildMaxHeap(vector<int>& nums){
        heapSize = nums.size();
        for(int i = (heapSize >> 1) - 1; i >= 0; --i)
            maxHeapify(nums, i);
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

// Constant space

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        
        while(low <= high){
            int mid = low + (high - low) / 2;
            int countMore = 0, countEqual = 0;
            for(int i = 0; i < n; ++i){
                if(nums[i] > mid)
                    ++countMore;
                else if(nums[i] == mid)
                    ++countEqual;
            }
            if(countMore < k && countMore + countEqual >= k)
                return mid;
        
            else if(countMore >= k)
                low  = mid + 1;
        
            else if(countMore < k && countMore + countEqual < k)
                high = mid - 1;
        }
        return 0;
    }
};
