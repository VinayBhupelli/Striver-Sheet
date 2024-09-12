#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int open = 0;
        int maxi = 0;
        for (auto x : s)
        {
            if (x == '(')
            {
                open++;
                if (open > maxi)
                    maxi = open;
            }
            else if (x == ')')
                open--;
        }
        return maxi;
    }
};