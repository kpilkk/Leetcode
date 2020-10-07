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

// Two pointer solution
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int max_water = 0;
        while(i < j){
            max_water = max(max_water, (j - i) * min(height[i], height[j]));
            if(height[i] < height[j])
                ++i;
            else
                --j;
        }
        return max_water;
    }
};
