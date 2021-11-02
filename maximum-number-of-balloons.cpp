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

// Faster solution
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0, b = 0, c = 0, d = 0, e = 0;
        
        for(int i = 0; i < text.size(); ++i){
            if(text[i] == 'b')
                ++a;
            else if(text[i] == 'a')
                ++b;
            else if(text[i] == 'l')
                ++c;
            else if(text[i] == 'o')
                ++d;
            else if(text[i] == 'n')
                ++e;
        }
        
        return min({a, b, c/2, d/2, e});
    }
};