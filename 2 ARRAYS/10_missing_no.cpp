#include <bits/stdc++.h>
using namespace std;
// Method 1: Check if each element from 0 to N exists or not n^2 solution
int missingNumber(vector<int> &a, int N)
{
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < N - 1; j++)
        {
            if (a[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
    return -1;
}
// Method 2: use vector of bool and traverse twice
int missingNumber(vector<int> &a, int N)
{
    int hash[N + 1] = {0};
    for (int i = 0; i < N - 1; i++)
        hash[a[i]]++;
    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
    return -1;
}
// Method 3: use math formula
int missingNumber(vector<int> nums)
{ // sum
    int len = nums.size();
    int sum = (len) * (len + 1) / 2;
    for (int i = 0; i < len; i++)
        sum -= nums[i];
    return sum;
}
// Method 4: XOR
int missingNumber(vector<int> nums)
{ // xor
    int res = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        res ^= i;
        res ^= nums[i];
    }
    return res;
}
