#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int j = 0;
        int res = INT_MAX;
        int start = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == t[j])
                j++;

            // Find it there exist a min window
            // if the starting elements skipped
            if (j == t.length())
            {
                j--;
                int end = i;
                while (j >= 0)
                {
                    if (s[i] == t[j])
                    {
                        j--;
                    }
                    i--;
                }
                i++;
                j++;
                if (end - i + 1 < res)
                {
                    res = end - i + 1;
                    start = i;
                }
            }
        }

        return res == INT_MAX ? "" : s.substr(start, res);
    }
};