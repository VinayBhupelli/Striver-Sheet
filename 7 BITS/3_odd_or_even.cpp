#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string oddEven(int N)
    {
        int bit = N & 1;
        if (bit)
            return "odd";
        else
            return "even";
    }
};