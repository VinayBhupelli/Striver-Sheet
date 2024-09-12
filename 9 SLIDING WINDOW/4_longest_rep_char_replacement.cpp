#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int i = 0, j = 0, n = s.size();
        unordered_map<char, int> hm;
        int res = 0;
        int maxi = 0;
        while (j < n)
        {
            hm[s[j]]++;
            maxi = max(maxi, hm[s[j]]);
            int winlen = j - i + 1;
            if (winlen - maxi > k)
            {
                hm[s[i]]--;
                i++;
            }
            res = max(res, (j - i + 1));
            j++;
        }
        return res;
    }
};