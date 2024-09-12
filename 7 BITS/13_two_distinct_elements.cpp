#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)
    {
        long long int temp = 0;
        for (int i = 0; i < N; i++)
            temp = temp ^ Arr[i];

        long long num1 = 0, num2 = 0;
        long long rightmost = (temp & (temp - 1)) ^ temp;
        for (int i = 0; i < N; i++)
        {
            if (Arr[i] & rightmost)
                num1 ^= Arr[i];
            else
                num2 ^= Arr[i];
        }
        return {max(num1, num2), min(num1, num2)};
    }
};