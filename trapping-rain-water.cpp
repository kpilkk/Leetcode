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
