#include <bits/stdc++.h>
using namespace std;

// Method 1: literaly pass the function to change whole row or col
// Method 2: take two arrays and mark them
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                    row[i] = 1, col[j] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
// Method 3: 0(1) space :
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 1;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] != 0)
                    if (matrix[i][0] == 0 || matrix[0][j] == 0)
                        matrix[i][j] = 0;
            }
        }
        if (matrix[0][0] == 0)
            for (int i = 0; i < n; i++)
            {
                matrix[0][i] = 0;
            }
        if (col0 == 1)
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
    }
};
