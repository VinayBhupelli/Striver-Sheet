#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void insert(stack<int> &s, int top)
{
    if (s.empty() || s.top() < top)
        s.push(top);
    else
    {
        int inside = s.top();
        s.pop();
        insert(s, top);
        s.push(inside);
    }
}
void sort()
{
    //  so stack is defined and named s
    if (s.empty())
        return;
    int top = s.top();
    s.pop();
    sort();
    insert(s, top);
}