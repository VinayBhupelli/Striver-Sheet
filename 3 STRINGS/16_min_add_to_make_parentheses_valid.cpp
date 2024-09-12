#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push('(');
            else if (s[i] == ')' && !st.empty())
                st.pop();
            else
                ans++;
        }
        return ans + st.size();
    }
};

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        int count = 0;
        int open = 0;
        int i = 0;
        while (i < n)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
            {
                if (open <= 0)
                    count++;
                else
                    open--;
            }
            i++;
        }
        if (open > 0)
            count += open;

        return count;
    }
};