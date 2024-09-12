#include <bits/stdc++.h>
using namespace std;
// Method 1: use n^2 loop to find diff of two elements
int maxProfit(vector<int> &arr) {
  int maxPro = 0;
  int n = arr.size();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] > arr[i]) {
        maxPro = max(arr[j] - arr[i], maxPro);
      }
    }
  }

  return maxPro;
}
// Method 2: find min while traversing elements and remove it from the curr
// element while traversing
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    int total_profit = 0;
    int mini = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      mini = min(mini, prices[i]);
      total_profit = max(total_profit, prices[i] - mini);
    }
    return total_profit;
  }
};