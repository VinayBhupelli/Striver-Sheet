#include <bits/stdc++.h>
using namespace std;
class MinStack
{
private:
    stack<long long> st;
    long long mini;

public:
    MinStack()
    {
        while (st.empty() == false)
            st.top();
        mini = INT_MAX;
    }

    void push(int val)
    {
        long long value = val;
        if (value < mini)
        {
            st.push(2 * value - mini);
            mini = value;
        }
        else
        {
            st.push(value);
        }
    }

    void pop()
    {
        if (st.empty())
            return;
        // modified
        if (st.top() < mini)
            mini = 2 * mini - st.top();
        st.pop();
    }

    int top()
    {
        if (st.empty())
            return -1;
        if (st.top() < mini)
            return mini;
        return st.top();
    }

    int getMin()
    {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */