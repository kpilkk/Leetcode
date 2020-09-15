// https://leetcode.com/problems/duplicate-zeros/submissions/

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int count = 0, i = 0;
        while(i < n){
            if(!arr[i])
                count += 2;
            else
                count++;
            if(count >= n)
                break;
            i++;
        }
        
        int j = n - 1;
        if(count > n){
            arr[j--] = arr[i--];
        }
        
        while(i >= 0 && j >= 0){
            if(arr[i]){
                arr[j--] = arr[i--];
            }
            else{
                arr[j--] = 0;
                arr[j--] = 0;
                i--;
            }
        }
    }
};
