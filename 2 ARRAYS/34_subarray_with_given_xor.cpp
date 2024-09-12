#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{
    int n = A.size();
    int count = 0;
    unordered_map<int, int> hm;

    int val = 0;
    hm[val]++;
    for (int i = 0; i < n; i++)
    {
        val ^= A[i];
        int temp = val ^ B;
        count += hm[temp];
        hm[val]++;
    }
    return count;
}