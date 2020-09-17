// https://leetcode.com/problems/check-if-it-is-a-straight-line/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n == 2) return true;
        float slope1, slope2;
        for(int i = 1; i < n - 1; ++i){
            if(coordinates[i][0] - coordinates[i - 1][0] == 0) // when denominator is zero
                slope1 = INT_MAX;
            else
                slope1 = (coordinates[i][1] - coordinates[i - 1][1]) / (float)(coordinates[i][0] - coordinates[i - 1][0]);
            if(coordinates[i + 1][0] - coordinates[i][0] == 0) // when denominator is zero
                slope2 = INT_MAX;
            else
                slope2 = (coordinates[i + 1][1] - coordinates[i][1]) / (float)(coordinates[i + 1][0] - coordinates[i][0]);
            if(slope1 != slope2)
                return false;
        }
        return true;
    }
};
