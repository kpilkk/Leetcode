// 1st slution

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

// 2nd solution
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
