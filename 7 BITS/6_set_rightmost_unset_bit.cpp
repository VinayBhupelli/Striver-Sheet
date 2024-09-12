#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBit(int n)
    {
        if (n & (n + 1))
            return n | (n + 1);

        return n;
    }
    int setBit1(int N)
    {
        for (int i = 0; i <= 31; i++)
        {
            if ((N & (1 << i)) == 0)
            {
                N = (N | (1 << i));
                return N;
            }
        }
    }
};