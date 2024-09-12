#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<int> st;
        st.push(num[0] - '0');
        for (int i = 1; i < num.size(); i++)
        {
            while (!st.empty() && k > 0 && st.top() > (num[i] - '0'))
            {
                st.pop();
                k--;
            }
            if (num[i] - '0' == 0 && st.empty() == true)
                continue;
            else
            {
                // cout<<num[i]-'0'<<" ";
                st.push(num[i] - '0');
            }
        }
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }
        string res = "";
        while (!st.empty())
        {
            res += st.top() + '0';
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res.size() == 0 ? "0" : res;
    }
};