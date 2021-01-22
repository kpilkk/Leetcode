// https://leetcode.com/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> sec(10, 0), gue(10, 0);
        
        for(int i = 0; i < secret.size(); ++i){
            if(secret[i] == guess[i])
                ++bulls;
            else{
                ++sec[secret[i] - '0'];
                ++gue[guess[i] - '0'];
            }
        }
        
        for(int i = 0; i < 10; ++i)
            cows += min(sec[i], gue[i]);
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
