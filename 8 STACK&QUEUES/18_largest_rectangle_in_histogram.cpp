#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        vector<int> leftsmall(n), rightsmall(n);
        // finding the left small element
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                leftsmall[i] = -1;
            else
                leftsmall[i] = st.top();
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        // finding the right small element
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                rightsmall[i] = n;
            else
                rightsmall[i] = st.top();
            st.push(i);
        }
        int maxarea = 0;
        for (int i = 0; i < n; i++)
        {
            int width = rightsmall[i] - leftsmall[i] - 1;
            maxarea = max(maxarea, (heights[i] * (width)));
        }
        return maxarea;
    }
};