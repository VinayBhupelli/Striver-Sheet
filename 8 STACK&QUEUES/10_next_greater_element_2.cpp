#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(2 * n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
            nums.push_back(nums[i]);

        for (int i = 2 * n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();
            st.push(nums[i]);
        }
        res.resize(n);
        return res;
    }
};