#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int searchInSorted(int arr[], int N, int K)
    {

        int low = 0, high = N - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == K)
                return 1;
            else if (arr[mid] < K)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};