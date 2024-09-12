#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxrectangle(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        int maxA = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i]))
            {
                int height = arr[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    // RS=i LS=st.top
                    width = i - st.top() - 1;
                maxA = max(maxA, height * width);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m + 1, 0);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }
            ans = max(ans, maxrectangle(height));
        }
        return ans;
    }
};