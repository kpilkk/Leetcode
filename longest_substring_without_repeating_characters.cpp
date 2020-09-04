// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Brute Force : Time Limit Exceded
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j <= n; ++j){
                if(allUnique(s, i, j))
                    ans = max(ans, j - i);
            }
        }
        return ans;
    } 
private:
    bool allUnique(string s, int start, int end){
        set<char> temp;
        for(int i = start; i < end; ++i) {
            char ch = s[i];
            if(temp.find(ch) != temp.end()) return false;
            temp.emplace(ch);
        }
        return true;
    }
};

// 2nd slution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        map<char, int> st;
        for(int j=0, i=0; j<n;++j){
            if(st.find(s[j])!=st.end())
                i = max(st[s[j]], i);
            ans = max(ans, j-i+1);
            st.insert(make_pair(s[j], j+1));
        }
        return ans;
    }
};

// 3rd solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> s;
        int ans = 0, i=0, j=0;
        while(i<n && j<n){
            if(s.find(s[j])==s.end()){
                s.insert(s[j++]);
                ans = max(ans ,j-i);
            }
            else
                s.erase(s[i++]);
        }
        return ans;
        }
};
