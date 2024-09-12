#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        string temp = strs[0];
        int m = temp.length();
        int mini = INT_MAX;

        for (int j = 1; j < n; j++)
        {
            int res = 0;
            for (int k = 0; k < strs[j].length() && k < m; k++)
            {
                if (strs[j][k] == temp[k])
                {
                    res++;
                }
                else
                {
                    break;
                }
            }
            mini = min(res, mini);
        }

        return strs[0].substr(0, mini);
    }
};

class Solution
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        string ans = "";
        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n - 1];
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};