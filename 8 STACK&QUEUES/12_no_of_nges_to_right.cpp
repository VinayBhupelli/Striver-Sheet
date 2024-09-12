#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
    {
        vector<int> ans(queries, 0);
        while (queries)
        {
            int count = 0;
            int ind = indices[queries - 1];
            for (int i = ind; i < n; i++)
                if (arr[i] > arr[ind])
                    count++;
            ans[queries - 1] = count;
            queries--;
        }
        return ans;
    }
};