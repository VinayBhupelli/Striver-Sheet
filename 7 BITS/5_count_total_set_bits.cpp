#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.
    int power(int n)
    {
        int i = 0;
        while (pow(2, i) <= n)
        {
            i++;
        }
        return i - 1;
    }
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        int x = power(n); // or log2(n)
        int val = pow(2, x - 1) * x;
        val += n - pow(2, x) + 1;
        val += countSetBits(n - pow(2, x));
        return val;
    }
};