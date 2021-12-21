// https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1<<n);
        
        for(int i = 0; i < 1<<n; ++i)
            ans[i] = i^(i>>1);
        
        return ans;
    }
};


// If the solution is in vector of strings
// https://www.geeksforgeeks.org/generate-n-bit-gray-codes/

class Solution
{
    public:
    vector<string> graycode(int n)
    {
        //code here
        vector<string> ans;
        
        ans.push_back("0");
        ans.push_back("1");
        
        int i = 1;
        while(i < n){
            for(int j = 0, n = ans.size(); j < n; ++j){
                ans.push_back(ans[n - j - 1]);
            }
            for(int j = 0; j < ans.size() / 2; ++j){
                ans[j] = '0' + ans[j];
            }
            for(int j = ans.size() / 2; j < ans.size(); ++j){
                ans[j] = '1' + ans[j];
            }
            ++i;
        }
        return ans;
    }
};