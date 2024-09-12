#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        vector<int> res;
        while (top <= bottom && left <= right)
        {
            // left to right
            for (int i = left; i <= right; i++)
                res.push_back(matrix[top][i]);
            // top to bottom
            top++;
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;
            // right to left
            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    res.push_back(matrix[bottom][i]);
                bottom--;
            }
            // bottom to top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};