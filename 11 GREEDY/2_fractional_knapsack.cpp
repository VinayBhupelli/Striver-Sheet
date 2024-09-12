#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool cmp(Item &a, Item &b)
    {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, &cmp);
        double ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].weight > W)
            {
                ans += W * ((double)arr[i].value / arr[i].weight);
                break;
            }
            ans += arr[i].value;
            W -= arr[i].weight;
        }
        return ans;
    }
};