#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findTwoElement(vector<int> arr, int n)
    {
        int sum1 = 0;
        for (auto x : arr)
            sum1 += x;
        int dup;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] *= -1;
            }
            else
            {
                dup = abs(arr[i]);
                break;
            }
        }
        int sum2 = ((arr.size()) * (arr.size() + 1)) / 2;
        return {dup, sum2 - (sum1 - dup)};
    }
};