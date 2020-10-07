// https://leetcode.com/problems/trapping-rain-water/

// Brute force method : O(n2)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        for(int i = 0; i < n; ++i){
            int left_max = 0, right_max = 0;
            for(int j = i; j >= 0; --j)
                left_max = max(left_max, height[j]);
            for(int j = i; j < n; ++j)
                right_max = max(right_max, height[j]);
            ans += min(left_max, right_max) - height[i];
        }
        return ans;
    }
};

// Dynamic Programming
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if(n == 0) return 0;
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for(int i = 1; i < n; ++i)
            left_max[i] = max(height[i], left_max[i - 1]);
        right_max[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; --i)
            right_max[i] = max(height[i], right_max[i + 1]);
        for(int i = 0; i < n; ++i)
            ans += min(left_max[i], right_max[i]) - height[i];
        return ans;
    }
};

// Two pointer
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while(left < right){
            if(height[left] < height[right])
                height[left] >= left_max ? (left_max = height[left++]) : ans += (left_max - height[left++]);
            else
                height[right] >= right_max ? (right_max = height[right--]) : ans += (right_max - height[right--]);
        }
        return ans;
    }
};
