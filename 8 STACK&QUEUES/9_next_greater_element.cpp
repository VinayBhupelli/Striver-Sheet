#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        unordered_map<int, int> hm;
        vector<int> res(m, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i])
            {
                st.pop();
            }
            if (st.empty())
                hm[nums2[i]] = -1;
            else
                hm[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < n; i++)
        {
            cout << hm[nums2[i]] << " ";
        }
        for (int i = 0; i < m; i++)
        {
            if (hm.find(nums1[i]) != hm.end())
                res[i] = hm[nums1[i]];
        }
        return res;
    }
};