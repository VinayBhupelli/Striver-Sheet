#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*You are required to complete below method */
    long long int countPS(string str)
    {
        int n = str.length();
        long long int mod = 1e9 + 7;
        vector<vector<long long int>> dp(n, vector<long long int>(n, 0));
        for (int g = 0; g < n; g++)
        {
            for (int i = 0, j = g; j < n; i++, j++)
            {
                if (g == 0)
                {
                    dp[i][j] = 1;
                }
                else if (g == 1)
                {
                    dp[i][j] = (str[i] == str[j]) ? 3 : 2;
                }
                else
                {
                    if (str[i] == str[j])
                    {
                        dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) % mod;
                    }
                    else
                    {
                        dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) % mod;
                    }
                }
            }
        }
        if (dp[0][n - 1] < 0)
        {
            return (dp[0][n - 1] + mod);
        }
        return dp[0][n - 1] % mod;
    }
};