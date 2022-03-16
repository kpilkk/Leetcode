// https://leetcode.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<=res[res.size()-1][1])
                res[res.size()-1][1] = max(res[res.size()-1][1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
