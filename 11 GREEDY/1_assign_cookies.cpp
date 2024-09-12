#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int j = s.size() - 1;
        for (int i = g.size() - 1; i >= 0 && j >= 0; i--)
        {
            if (s[j] >= g[i])
            {
                count++;
                j--;
            }
        }
        return count;
    }
};