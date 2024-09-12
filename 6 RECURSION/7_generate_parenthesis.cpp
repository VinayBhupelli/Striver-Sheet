#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void allbinarystrings(string s, int open, int close, vector<string> &ans)
    {
        int len = s.size();
        if (open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }
        if (open > 0)
            allbinarystrings(s + '(', open - 1, close, ans);

        if (close > 0 && close > open)
            allbinarystrings(s + ')', open, close - 1, ans);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        allbinarystrings("", n, n, ans);
        return ans;
    }
};