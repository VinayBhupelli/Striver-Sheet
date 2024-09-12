#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> nse(n), pse(n);
        // Initially keep all the elements as smaller
        for (int i = 0; i < n; i++)
        {
            pse[i] = i;
            nse[i] = n - i - 1;
        }
        // stack to find nse
        stack<int> st1;
        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && arr[st1.top()] > arr[i])
            {
                nse[st1.top()] = i - st1.top() - 1;
                st1.pop();
            }
            st1.push(i);
        }
        // stack to find pse
        stack<int> st2;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && arr[st2.top()] >= arr[i])
            {
                pse[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }
        int ans = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i] * (1LL) * (pse[i] + 1) % mod * (nse[i] + 1) % mod;
            ans %= mod;
        }
        return ans;
    }
};