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

// Approach 3: Top-Down Approach using Memoization
class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        vector<int> cache(N + 1, -1);
        cache[0] = 0;
        cache[1] = 1;
        return memoize(N, cache);
    }
    int memoize(int N, vector<int>& cache){
        if(cache[N] != -1)
            return cache[N];
        
        cache[N] = memoize(N - 1, cache) + memoize(N - 2, cache);
        return cache[N];
    }
};

// Approach 4: Iterative Top-Down Approach
class Solution {
public:
    int fib(int N) {
        if(N <= 1) return N;
        if(N == 2) return 1;
        
        int current  = 0;
        int prev1 = 1;
        int prev2 = 1;
        
        for(int i = 3; i <= N; ++i){
            current = prev1 + prev2;
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};

// Approach 5: Matrix Exponentiation
class Solution {
public:
    int fib(int N) {
        vector<vector<int>> a = {{ 1, 1}, {1 , 0}};
        vector<vector<int>> ans = {{ 1, 0}, {0, 1}};
        
        while(N){
            if(N & 1){
                multiply(ans, a);
                N--;
            }
            else{
                multiply(a, a);
                N /= 2;
            }
        }
        return ans[0][1];
    }
    
    void multiply(vector<vector<int>>& A, vector<vector<int>> B){
        int x = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        int y = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        int z = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        int w = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        
        A[0][0] = x;
        A[0][1] = y;
        A[1][0] = z;
        A[1][1] = w;
    }
};

// Approach 6: Math
class Solution {
public:
    int fib(int N) {
        double phi = ( 1 + sqrt(5)) / 2;
        return round(pow(phi, N) / sqrt(5));
    }
};
