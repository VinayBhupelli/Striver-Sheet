#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sieve(int n)
    {
        if (n <= 2)
            return 0;
        vector<bool> primes(n, true);
        primes[0] = primes[1] = false;
        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            if (primes[i])
            {
                count++;
                for (int j = i * 2; j < n; j += i)
                    primes[j] = false;
            }
        }
        return count;
    }
    int countPrimes(int n)
    {
        int count = sieve(n);
        return count;
    }
};