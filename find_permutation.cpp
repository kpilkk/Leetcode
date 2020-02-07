// Solution using stack
class Solution{
public:
    findPerm(const string A, int B) {
        int n = A.size();
        vector<int> ans(n+1);
        stack<int> s;
        int j = 0;
        for(int i=1;i<=n;++i){
            if(A[i-1]=='I'){
                s.push(i);
                while(!s.empty()){
                    ans[j++] = s.top();
                    s.pop();
                }
            }
            else{
                s.push(i);
            }
        }
        s.push(n+1);
        while(!s.empty()){
            ans[j++] = s.top();
            s.pop();
        }
        return ans;
    }
};
