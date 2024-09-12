#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        return n >> k & 1;
    }
};