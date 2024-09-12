#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> hm1, hm2;
        if (s.size() != t.size())
            return false;
        for (int i = 0; i < s.size(); i++)
        {
            if (hm1.find(s[i]) == hm1.end() && hm2.find(t[i]) == hm2.end())
            {
                hm1[s[i]] = t[i];
                hm2[t[i]] = s[i];
            }
            else if (hm1[s[i]] != t[i] || hm2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};