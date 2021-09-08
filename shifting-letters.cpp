// https://leetcode.com/problems/shifting-letters/

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        for(int i = 0; i < shifts.size(); ++i)
            shifts[i] %= 26;
        
        int sum = 0;
        for(const int n: shifts)
            sum += n;
        
        for(int i = 0; i < shifts.size() - 1; ++i){
            int prev = shifts[i];
            shifts[i] = sum;
            //cout << shifts[i] << " ";
            sum -= prev;
        }
        //cout << shifts[shifts.size() - 1];
        
        for(int i = 0; i < s.size(); ++i){
            int temp = ((s[i] - 'a') + shifts[i]) % 26;
            s[i] = temp + 'a';
        }
        
        return s;
    }
};