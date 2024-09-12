#include <bits/stdc++.h>
using namespace std;
// Method 1: find the largest element in one loop & in another loop find the
// second largest
class Solution {
 public:
  int print2largest(int arr[], int n) {
    int ans = INT_MIN;
    int ans = -1;
    for (int i = 0; i < n; i++)
      if (arr[i] > ans) ans = arr[i];
    int second = -1;
    for (int i = 0; i < n; i++)
      if (arr[i] != ans) second = max(second, arr[i]);
    return second;
  }
};
// Method 2: find the largest element through loop & in same loop if its not
// largest check it with second largest
class Solution {
 public:
  int print2largest(int arr[], int n) {
    int first = arr[0];
    int second = -1;
    for (int i = 1; i < n; i++) {
      if (arr[i] > first) {
        second = first;
        first = arr[i];
      } else if (arr[i] < first)
        second = (arr[i] > second) ? arr[i] : second;
    }
    return second;
  }
};
