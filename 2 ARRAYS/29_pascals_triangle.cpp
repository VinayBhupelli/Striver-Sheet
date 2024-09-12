#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++)
        {
            ans[i].resize(i + 1);
            ans[i][0] = ans[i][i] = 1;
            for (int prev = 1; prev < i; prev++)
                ans[i][prev] = ans[i - 1][prev - 1] + ans[i - 1][prev];
        }
        return ans;
    }
};