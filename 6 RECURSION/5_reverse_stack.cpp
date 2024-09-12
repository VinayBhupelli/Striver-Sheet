#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Reverse(stack<int> &St)
    {
        queue<int> q;
        while (!St.empty())
        {
            q.push(St.top());
            St.pop();
        }
        while (!q.empty())
        {
            St.push(q.front());
            q.pop();
        }
    }
};
// Optimised
class Solution
{
public:
    void insertAtBottom(stack<int> &St, int x)
    {
        if (St.empty())
        {
            St.push(x);
            return;
        }

        int a = St.top();
        St.pop();
        insertAtBottom(St, x);
        St.push(a);
    }

    void solve(stack<int> &St)
    {
        if (St.empty())
        {
            return;
        }

        int x = St.top();
        St.pop();
        solve(St);
        insertAtBottom(St, x);
    }
    void Reverse(stack<int> &St)
    {
        solve(St);
    }
};