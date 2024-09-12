#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // finding the lonest palindromic substring possible from index 0
    // reverse the string left over after the index and add it to the starting
    int lps(string s)
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
        return lps[s.size() - 1];
    }
    string shortestPalindrome(string s)
    {
        string temp = s;
        reverse(temp.begin(), temp.end());
        string str = s + "#" + temp;
        int i = lps(str);

        string rev = s.substr(i);
        reverse(rev.begin(), rev.end());
        return rev + s;
    }
};