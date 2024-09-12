#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string S)
    {
        // Neetcode Explaination
        string res = "";
        int len = INT_MIN;
        int n = S.size();
        for (int i = 0; i < n; i++)
        {
            // Odd Length
            int l = i, r = i;
            while (l >= 0 && r < n && S[l] == S[r])
            {
                if (r - l + 1 > len)
                {
                    len = r - l + 1;
                    res = S.substr(l, len);
                }
                l -= 1;
                r += 1;
            }
            // Even Length
            l = i, r = i + 1;
            if (i + 1 < n)
                while (l >= 0 && r < n && S[l] == S[r])
                {
                    if (r - l + 1 > len)
                    {
                        len = r - l + 1;
                        res = S.substr(l, len);
                    }
                    l -= 1;
                    r += 1;
                }
        }
        return res;
    }
};