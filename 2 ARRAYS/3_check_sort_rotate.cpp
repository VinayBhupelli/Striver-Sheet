#include <bits/stdc++.h>
using namespace std;
// Check sorted or not
// Method 1:
bool isSorted(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[i]) return false;
    }
  }
  return true;
}
// Method 2:
bool isSorted(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) return false;
  }

  return true;
}

// Question: check if the array is sorted and check whether it is rotated only
// once Method 1: Check in n^2 loop: whether each element is smaller than next
// elements Method 2: Check only adjacent
class Solution {
 public:
  bool check(vector<int> &nums) {
    bool flag = false;
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
      // if not greater once its ok as it is rotated
      // but if twice happened even though happened then it is not sorted and
      // rotated
      if (nums[i + 1] - nums[i] < 0) {
        if (flag == true || nums[n - 1] > nums[0]) return false;
        flag = true;
      }
    }
    return true;
  }
};
// another code
bool check(vector<int> &A) {
  for (int i = 0, k = 0; i < A.size(); ++i)
    if (A[i] > A[(i + 1) % A.size()] && ++k > 1) return false;
  return true;
}