#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int n = s.size();
        int ind = 0;
        while (s[ind] == ' ')
            ind++;
        bool pos = s[ind] == '+';
        bool neg = s[ind] == '-';
        if (neg || pos)
            ind++;

        double result = 0;
        while (ind < n && s[ind] >= '0' && s[ind] <= '9')
        {
            result = result * 10 + (s[ind] - '0');
            ind++;
        }
        if (neg)
            result *= -1;
        if (result > INT_MAX)
            return INT_MAX;
        else if (result < INT_MIN)
            return INT_MIN;
        else
            return result;
    }
};