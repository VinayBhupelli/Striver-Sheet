#include <bits/stdc++.h>
using namespace std;
// Method 1: Bruteforce
vector<int> printLeadersBruteForce(int arr[], int n) {
  vector<int> ans;

  for (int i = 0; i < n; i++) {
    bool leader = true;
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
        leader = false;
        break;
      }
    if (leader) ans.push_back(arr[i]);
  }

  return ans;
}
// Method 2: Optimal
class Solution {
 public:
  vector<int> leaders(int a[], int n) {
    vector<int> res;
    int maxitill = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      if (res.size() == 0 || a[i] >= maxitill) {
        res.push_back(a[i]);
        maxitill = a[i];
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};