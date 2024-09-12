#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        int i = 0, j = 0;
        int n = s.size();
        int ans = -1;
        unordered_map<char, int> hm;
        while (j < n)
        {
            hm[s[j]]++;
            while (hm.size() > k)
            {
                if (hm[s[i]] == 1)
                    hm.erase(s[i]);
                else
                    hm[s[i]]--;
                i++;
            }
            if (hm.size() == k)
                ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};