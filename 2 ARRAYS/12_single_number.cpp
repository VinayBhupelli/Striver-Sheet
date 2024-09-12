#include <bits/stdc++.h>
using namespace std;
// Method 1: check each element through loop whether present again or not n^2
// solution
int getSingleElement(vector<int> &arr) {
  int n = arr.size();
  for (int i = 0; i < n; i++) {
    int num = arr[i];
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (arr[j] == num) cnt++;
    }
    if (cnt == 1) return num;
  }
  return -1;
}

// Method 2: Hashing
int getSingleElement(vector<int> &arr) {
  int n = arr.size();
  int maxi = arr[0];
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, arr[i]);
  }
  vector<int> hash(maxi + 1, 0);
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }
  for (int i = 0; i < n; i++) {
    if (hash[arr[i]] == 1) return arr[i];
  }
  return -1;
}

// Method 3: Hashing with default structure
int getSingleElement(vector<int> &arr) {
  int n = arr.size();
  map<int, int> mpp;
  for (int i = 0; i < n; i++) {
    mpp[arr[i]]++;
  }
  for (auto it : mpp) {
    if (it.second == 1) return it.first;
  }
  return -1;
}
// Method 4: XOR
class Solution {
 public:
  int singleNumber(vector<int> &nums) {
    int n = nums.size();
    int val = 0;
    for (int i = 0; i < nums.size(); i++) val ^= nums[i];
    return val;
  }
};