#include <bits/stdc++.h>
using namespace std;
// Method 1: check each element frquency in the entire array again
int majorityElement(vector<int> v) {
  int n = v.size();
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (v[j] == v[i]) {
        cnt++;
      }
    }
    if (cnt > (n / 2)) return v[i];
  }
  return -1;
}
// Method 2: using hashmap to store frequency values
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> hm;
    int res = 0;
    for (auto x : nums) {
      hm[x]++;
      if (hm[x] > nums.size() / 2) {
        res = x;
        break;
      }
    }
    return res;
  }
};

// Optimized Method
// find the logic behind the optimal code
class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    // Moore Voting Algorithm
    int element = 0;
    int count = 0;

    for (auto x : nums) {
      if (count == 0) {
        element = x;
        count = 1;
      } else if (x == element)
        count++;
      else
        count--;
    }
    return element;
  }
};