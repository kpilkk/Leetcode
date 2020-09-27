// https://leetcode.com/problems/fibonacci-number/

// Approach 1 : Recursion
class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        return fib(N - 1) + fib(N - 2);
    }
};

// Approach 2: Bottom-Up Approach using Memoization
class Solution {
public:
    int fib(int N) {
        int arr[N + 1];
        arr[0] = 0;
        if(N > 0)
            arr[1] = 1;
        for(int i = 2; i <= N; ++i)
            arr[i] = arr[i - 1] + arr[i - 2];
        return arr[N];
    }
};