#include <bits/stdc++.h>
using namespace std;
// Method 1: place non zero elements in vector and fill remaining elements as
// zero
vector<int> moveZeros(int n, vector<int> a) {
  vector<int> temp;
  for (int i = 0; i < n; i++) {
    if (a[i] != 0) temp.push_back(a[i]);
  }
  int nz = temp.size();
  for (int i = 0; i < nz; i++) {
    a[i] = temp[i];
  }
  for (int i = nz; i < n; i++) {
    a[i] = 0;
  }
  return a;
}
// Method 2: using Two Pointer place all non zero elements at starting & initize
// remaining as zero Method 3: Find first starting zero and swap the non zero
// elements with zero elements
class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int j = -1;
    for (int i = 0; i < n; i++) {
      if (nums[i] == 0) {
        j = i;
        break;
      }
    }
    if (j == -1) return;
    for (int i = j + 1; i < n; i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[j]);
        j++;
      }
    }
  }
};