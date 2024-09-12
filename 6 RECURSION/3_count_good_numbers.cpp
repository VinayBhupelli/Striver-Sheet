#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mod = 1e9 + 7;
    long long solve(long long x, long long n)
    {
        if (n == 0)
        {
            return 1;
        }
        long long val = solve(x, n / 2);
        val *= val;
        val %= mod;
        if (n % 2)
        {
            val *= x;
        }
        return val % mod;
    }
    int countGoodNumbers(long long n)
    {
        long long odd = n / 2;
        long long even = n - odd;
        int ans = (solve(5, even) * solve(4, odd)) % mod;
        return ans;
    }
};