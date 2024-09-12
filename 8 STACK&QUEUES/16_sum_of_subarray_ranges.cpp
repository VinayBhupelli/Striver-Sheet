#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long sumSubarrayMins(vector<int> &arr)
    {
        int n = arr.size();
        vector<long long> nse(n), pse(n);
        // Initially keep all the elements as smaller
        for (int i = 0; i < n; i++)
        {
            pse[i] = i;
            nse[i] = n - i - 1;
        }
        // stack to find nse
        stack<long long> st1;
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
        stack<long long> st2;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && arr[st2.top()] >= arr[i])
            {
                pse[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i] * (pse[i] + 1) * (nse[i] + 1);
        }
        return ans;
    }
    long long sumSubarrayMaxs(vector<int> &arr)
    {
        int n = arr.size();
        vector<long long> nge(n), pge(n);
        for (int i = 0; i < n; i++)
        {
            pge[i] = i;
            nge[i] = n - i - 1;
        }
        // stack to find nge
        stack<long long> st1;
        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && arr[st1.top()] < arr[i])
            {
                nge[st1.top()] = i - st1.top() - 1;
                st1.pop();
            }
            st1.push(i);
        }
        // stack to find pge
        stack<long long> st2;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && arr[st2.top()] <= arr[i])
            {
                pge[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += arr[i] * (pge[i] + 1) * (nge[i] + 1);
        }
        return ans;
    }
    long long subArrayRanges(vector<int> &nums)
    {
        long long ans = sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
        return ans;
    }
};