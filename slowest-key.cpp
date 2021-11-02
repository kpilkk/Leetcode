// https://leetcode.com/problems/slowest-key/

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        pair<char, int> ans;
        ans = make_pair(keysPressed[0], releaseTimes[0]);
        
        int n = releaseTimes.size();
        
        for(int i = 1; i < n; ++i){
            int diff = releaseTimes[i] - releaseTimes[i - 1];
            if(diff == ans.second){
                if(ans.first < keysPressed[i]){
                    ans.first = keysPressed[i];
                    ans.second = diff;
                }
            }
            else if(diff > ans.second){
                ans.first = keysPressed[i];
                ans.second = diff;
            }
        }
        
        return ans.first;
    }
};