#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMaxHeap(int arr[], int n)
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (2 * i + 1 < n && arr[i] < arr[2 * i + 1])
                return false;
            if (2 * i + 2 < n && arr[i] < arr[2 * i + 2])
                return false;
        }
        return true;
    }
};