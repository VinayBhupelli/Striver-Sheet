#include <bits/stdc++.h>
using namespace std;

// 0(1) space
class Solution
{
public:
    int findMatching(string text, string pat)
    {
        int n = text.size();
        int m = pat.size();

        if (m > n)
            return -1;
        for (int i = 0; i < n - m + 1; i++)
        {
            if (text.substr(i, m) == pat)
                return i;
        }
        return -1;
    }
};

// LPS
class Solution
{
public:
    vector<int> lps(string s)
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
        return lps;
    }
    int strStr(string haystack, string needle)
    {
        vector<int> arrlps = lps(needle);
        int n = haystack.length();
        int m = needle.length();
        int i = 0, j = 0;
        while (i < n)
        {
            if (haystack[i] == needle[j])
            {
                i += 1;
                j += 1;
            }
            else
            {
                if (j != 0)
                {
                    j = arrlps[j - 1];
                }
                else
                {
                    i += 1;
                }
            }
            if (j == m)
            {
                return i - j;
            }
        }
        return -1;
    }
};