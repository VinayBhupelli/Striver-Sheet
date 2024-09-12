#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {

        if (t.size() > s.size())
        {
            return "";
        }
        int n = s.size();

        unordered_map<char, int> hm1, hm2;
        for (auto x : t)
            hm1[x]++;

        int currlen = 0, totallen = hm1.size();
        int mini = INT_MAX, st = 0, l = 0;

        for (int r = 0; r < n; r++)
        {

            hm2[s[r]]++;
            if ((hm1[s[r]] > 0) && (hm2[s[r]] == hm1[s[r]]))
                currlen++;

            while (currlen == totallen)
            {
                if (r - l + 1 < mini)
                {
                    mini = r - l + 1;
                    st = l;
                }

                if ((hm1[s[l]] > 0) && (hm2[s[l]] - 1 < hm1[s[l]]))
                    currlen--;

                hm2[s[l]]--;
                l++;
            }
        }

        return (mini != INT_MAX) ? s.substr(st, mini) : "";
    }
};