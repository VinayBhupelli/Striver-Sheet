#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> open, stars;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                open.push(i);
            }
            else if (s[i] == '*')
                stars.push(i);
            else
            {
                if (!open.empty())
                    open.pop();
                else if (!stars.empty())
                {
                    stars.pop();
                }
                else
                    return false;
            }
        }
        while (!open.empty() && !stars.empty() && stars.top() > open.top())
        {
            open.pop();
            stars.pop();
        }
        return open.empty();
    }
};