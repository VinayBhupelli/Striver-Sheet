#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLen(vector<int> &A, int N)
    {
        int len = 0;
        int sum = 0;
        unordered_map<int, int> hm;
        int K = 0;
        hm[0] = 1;
        for (int i = 0; i < N; i++)
        {
            sum += A[i];
            if (sum == K)
            {
                len = max(len, i + 1);
            }
            // sum-K here not K-sum
            int rem = sum - K;
            if (hm.find(rem) != hm.end())
            {
                int index = hm[rem];
                len = max(len, i - index);
            }
            if (hm.find(sum) == hm.end())
                hm[sum] = i;
        }
        return len;
    }
};