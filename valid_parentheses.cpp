// https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        int n = s.size();
        if(n==0) return true;
        
        for(int i=0; i<n; ++i){
            char temp = s.at(i);
            if(temp == '(' || temp == '{' || temp == '[')
                t.push(temp);
            else if(!t.empty()){
                if((t.top()=='(' && temp == ')') || (t.top()=='[' && temp == ']') || (t.top()=='{' && temp == '}'))
                        t.pop();
                else return false;
            }
            else return false;
        }
        if(t.empty()) return true;
        else return false;
    }
};


// Another form of the above solution
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        if(n % 2 != 0)
            return 0;
        
        stack<char> temp;
        int i = 0;
        while(n--){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                temp.emplace(s[i]);
            }
            else if(!temp.empty()){
                char tmp = temp.top();
                temp.pop();
                if((tmp == '(' && s[i] != ')') || (tmp == '[' && s[i] != ']') || (tmp == '{' && s[i] != '}'))
                    return false;
            }
            else
                return false;
            ++i;
        }
        if(temp.empty())
            return true;
        return false;
    }
};
