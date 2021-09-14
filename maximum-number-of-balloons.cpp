// https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        m['b'] = 0;
        m['a'] = 0;
        m['l'] = 0;
        m['o'] = 0;
        m['n'] = 0;
        
        for(int i = 0; i < text.size(); ++i){
            if(text[i] == 'b' || text[i] == 'a' || text[i] == 'l' || text[i] == 'o' || text[i] == 'n'){
                m[text[i]]++;
            }
        }
        
        return min({m['b'], m['a'], m['l']/2, m['o']/2, m['n']});
    }
};