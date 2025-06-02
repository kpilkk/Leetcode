// https://leetcode.com/problems/divide-two-integers/description/

// Brute Force -> TLE
#include <algorithm>
#include <climits>

using namespace std;

// class Solution
// {
// public:
//     int divide(int dividend, int divisor)
//     {
//         if (dividend == 0)
//             return 0;

//         int sign = ((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor > 0)) ? 1 : -1;

//         long long a = abs((long long)dividend);
//         long long b = abs((long long)divisor);

//         long long quotient = 0;
//         while (a >= b)
//         {
//             a -= b;
//             ++quotient;
//         }

//         if (quotient > INT_MAX && sign == 1)
//             return INT_MAX;
//         if (quotient > (long long)INT_MAX + 1 && sign == -1)
//             return INT_MIN;
//         return sign * quotient;
//     }
// };

// Better solution
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quotient = 0;

        for (int i = 31; i >= 0; --i)
        {
            if ((b << i) <= a)
            {
                a -= (b << i);
                quotient |= (1 << i);
            }
        }

        return sign * quotient;
    }
};