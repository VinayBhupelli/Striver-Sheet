#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sieve() {}

    vector<int> findPrimeFactors(int N)
    {
        vector<int> result;
        for (int i = 2; i <= sqrt(N); i++)
        {
            if (N % i == 0)
            {
                result.push_back(i);
                N /= i;
                while (N % i == 0)
                {
                    result.push_back(i);
                    N /= i;
                }
            }
        }
        if (N != 1)
            result.push_back(N);
        return result;
    }
};