#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        int len = 0;
        int i = 1;
        vector<int> lps(s.size(), 0);
        while (i < s.size())
        {
            if (s[len] == s[i])
            {
                lps[i] = len + 1;
                len += 1;
                i += 1;
            }
            else
            {
                if (len != 0)
                {
                    len = lps[len - 1];
                }
                else
                {
                    lps[i] = 0;
                    i += 1;
                }
            }
        }
        int ind = lps[s.size() - 1];
        return s.substr(0, ind);
    }
};