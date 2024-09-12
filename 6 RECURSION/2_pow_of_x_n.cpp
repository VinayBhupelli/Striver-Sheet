#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double solve(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }
        double val = solve(x, n / 2);
        val *= val;
        if (n % 2)
        {
            val *= x;
        }
        return val;
    }
    double myPow(double x, int n)
    {
        if (n < 0)
        {
            n = abs((long)n);
            return 1.0 / solve(x, n);
        }
        return solve(x, n);
    }
};