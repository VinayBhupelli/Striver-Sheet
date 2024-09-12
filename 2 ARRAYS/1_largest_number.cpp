#include <bits/stdc++.h>
using namespace std;

// Method 1: sort & return last index element
class Solution {
 public:
  int largest(vector<int> &arr, int n) {
    sort(arr.begin(), arr.end());
    return arr[n - 1];
  }
};
// Method 2: loop through elements and find the max element
class Solution {
 public:
  int largest(vector<int> &arr, int n) {
    int maxi = arr[0];
    for (int i = 1; i < n; i++) {
      maxi = max(maxi, arr[i]);
    }
    return maxi;
  }
};
