#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            arr.push_back({end[i], start[i]});
        }
        sort(arr.begin(), arr.end());
        // for(int i=0;i<n;i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        int last_end = arr[0].first;
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i].second > last_end)
            {
                count++;
                last_end = arr[i].first;
            }
        }
        return count;
    }
};