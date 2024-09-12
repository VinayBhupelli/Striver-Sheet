#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long low, long long mid, long long high)
    {
        vector<long long> temp;
        long long left = low;
        long long right = mid + 1;
        long long count = 0;
        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                count += (mid - left + 1);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }
        for (long long i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        return count;
    }
    long long mergesort(long long arr[], long long low, long long high)
    {
        long long count = 0;
        if (low >= high)
            return count;
        long long mid = (low + high) / 2;
        count += mergesort(arr, low, mid);
        count += mergesort(arr, mid + 1, high);
        count += merge(arr, low, mid, high);

        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergesort(arr, 0, N - 1);
    }
};