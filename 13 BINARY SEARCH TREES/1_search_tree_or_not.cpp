#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBSTTraversal(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] - arr[i] <= 0)
                return false;
        }
        return true;
    }
};