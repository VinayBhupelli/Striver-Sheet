#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> m;
        int left = 0, right = 0;
        int n = s.size();
        vector<int> maps(256, -1);
        int len = 0;
        while (right < n)
        {
            if (maps[s[right]] != -1)
                left = max(maps[s[right]] + 1, left);
            maps[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};