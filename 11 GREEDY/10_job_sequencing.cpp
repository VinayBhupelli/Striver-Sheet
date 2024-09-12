#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<pair<int, int>> order;
        int time = -1;
        for (int i = 0; i < n; i++)
        {
            order.push_back({arr[i].profit, arr[i].dead});
            if (arr[i].dead > time)
            {
                time = arr[i].dead;
            }
        }
        sort(order.rbegin(), order.rend());
        int count = 0;
        int profit = 0;

        // for(int i=0;i<n;i++){
        //     cout<<order[i].first<<" "<<order[i].second<<endl;
        // }
        vector<int> result(time + 1, -1);
        for (int i = 0; i < n; i++)
        {
            int curr = order[i].second;
            if (result[curr] == -1)
            {
                profit += order[i].first;
                result[curr] = curr;
                count++;
            }
            else
            {
                int j = curr - 1;
                while (j > 0)
                {
                    if (result[j] == -1)
                    {
                        profit += order[i].first;
                        result[j] = j;
                        count++;
                        break;
                    }
                    j--;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(profit);
        return ans;
    }
};