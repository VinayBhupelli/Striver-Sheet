#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr + 0, arr + n);
        sort(dep + 0, dep + n);

        int count = 0;
        int end = 0;
        int t = dep[0];
        for (int i = 0; i < n; i++)
        {
            // check the depature of existing
            // with that of arrival one
            if (arr[i] > t)
            {
                // free platform available and hence used
                // t updated to time when another platform will be free
                end++;
                t = dep[end];
            }
            else
            {
                // no free platform available so new platform required
                count++;
            }
        }
        return count;
    }
};
