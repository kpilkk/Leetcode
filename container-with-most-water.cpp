// https://leetcode.com/problems/container-with-most-water/

// Brute Force : TLE
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int n = height.size();
        for(int i = 1; i < n; ++i){
            for(int j = i + 1; j <= n; ++j){
                int area = min(height[i - 1], height[j - 1]) * (j - i);
                max_area = max(max_water, area);
            }
        }
        return max_water;
    }
};
