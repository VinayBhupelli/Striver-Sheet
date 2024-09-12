#include <bits/stdc++.h>
using namespace std;

// in right rotation first reverse array
// where in left rotation reverse array at last

// Right Rotation
class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};
// Left Rotation
// by only one element
class Solution {
 public:
  void solve(int arr[], int n) {
    int temp[n];
    for (int i = 1; i < n; i++) temp[i - 1] = arr[i];
    temp[n - 1] = arr[0];
    for (int i = 0; i < n; i++) cout << temp[i] << " ";
    cout << endl;
  }
};
// any no of elements
class Solution {
 public:
  void rotate(vector<int> &nums, int k) {
    k = k % nums.size();
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    reverse(nums.begin(), nums.end());
  }
};