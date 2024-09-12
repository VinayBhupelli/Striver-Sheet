#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long int solve(string s, int k)
    {
        vector<long long int> hm(26, 0);

        long long int count = 0, j = 0, distinct = 0, n = s.size();

        for (long long int i = 0; i < n; i++)
        {
            if (hm[s[i] - 'a'] == 0)
                distinct++;
            hm[s[i] - 'a']++;
            while (distinct > k)
            {
                hm[s[j] - 'a']--;
                if (hm[s[j] - 'a'] == 0)
                    distinct--;
                j++;
            }
            if (distinct <= k)
                count += i - j + 1;
        }
        return count;
    }
    long long int substrCount(string s, int k)
    {
        return solve(s, k) - solve(s, k - 1);
    }
};