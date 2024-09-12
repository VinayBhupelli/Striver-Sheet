#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    int m = B.size();
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = A[i] + B[j];
            if (pq.size() < C)
                pq.push(sum);
            else if (sum > pq.top())
            {
                pq.pop();
                pq.push(sum);
            }
            else
                break;
        }
    }
    vector<int> result;
    while (C-- && pq.size() > 0)
    {
        result.push_back(pq.top());
        pq.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}
