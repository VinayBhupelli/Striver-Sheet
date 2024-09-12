#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution
{
public:
    int solve(int price[], int ind, int len, int n)
    {
        if (len == 0)
            return 0;
        if (ind == n)
            return -1e9;
        int nottake = solve(price, ind + 1, len, n);
        int take = -1e9;
        if (ind + 1 <= len)
            take = price[ind] + solve(price, ind, len - (ind + 1), n);
        return max(take, nottake);
    }
    int cutRod(int price[], int n)
    {
        return solve(price, 0, n, n);
    }
};
// Memorization
class Solution
{
public:
    int solve(int price[], int ind, int len, int n, vector<vector<int>> &dp)
    {
        if (len == 0)
            return 0;
        if (ind == n)
            return -1e9;
        if (dp[ind][len] != -1)
            return dp[ind][len];
        int nottake = solve(price, ind + 1, len, n, dp);
        int take = -1e9;
        if (ind + 1 <= len)
            take = price[ind] + solve(price, ind, len - (ind + 1), n, dp);
        return dp[ind][len] = max(take, nottake);
    }
    int cutRod(int price[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(price, 0, n, n, dp);
    }
};

// Tabulation
