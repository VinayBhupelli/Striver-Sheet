#include <bits/stdc++.h>
using namespace std;

vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> ans;
    for (int num = 0; num < (1 << n); num++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            // check if the ith bit is set or not
            if (num & (1 << i))
            {
                sub += s[i];
            }
        }
        if (sub.length() > 0)
        {
            ans.push_back(sub);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}
// Optimised
class Solution
{
public:
    void solve(int ind, int n, vector<int> &sq, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (ind == n)
        {
            ans.push_back(sq);
            return;
        }
        solve(ind + 1, n, sq, nums, ans);
        sq.push_back(nums[ind]);
        solve(ind + 1, n, sq, nums, ans);
        sq.pop_back();
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> sq;
        solve(0, nums.size(), sq, nums, ans);
        return ans;
    }
};