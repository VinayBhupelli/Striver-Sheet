#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void print_divisors(int n)
    {
        int i;
        for (i = 1; i < sqrt(n); i++)
        {
            if (n % i == 0)
                cout << i << " ";
        }
        // 6*6=36
        if (i != sqrt(n))
            i--;
        for (i; i >= 1; i--)
        {
            if (n % i == 0)
            {
                cout << n / i << " ";
            }
        }
    }
};