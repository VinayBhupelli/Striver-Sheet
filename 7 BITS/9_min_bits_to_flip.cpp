#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minBitFlips(int start, int goal)
    {
        int flips = 0;
        while (start || goal)
        {
            if (start % 2 != goal % 2)
                flips++;

            start /= 2;
            goal /= 2;
        }
        return flips;
    }
};

// optimised
class Solution
{
public:
    int minBitFlips(int start, int goal)
    {

        int val = (start ^ goal);
        int count = 0;
        while (val)
        {
            if (val & 1)
                count++;
            val = val >> 1;
        }
        return count;
    }
};