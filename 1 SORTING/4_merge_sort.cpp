#include <bits/stdc++.h>
using namespace std;
// Divide and Conquer Algorithm

void merge(vector<int> &arr, int low, int mid, int high) {
  vector<int> temp;
  int left = low;
  int right = mid + 1;
  while (left <= mid && right <= high) {
    if (arr[left] <= arr[right]) {
      temp.push_back(arr[left]);
      left++;
    } else {
      temp.push_back(arr[right]);
      right++;
    }
  }
  while (left <= mid) {
    temp.push_back(arr[left]);
    left++;
  }
  while (right <= high) {
    temp.push_back(arr[right]);
    right++;
  }
  for (int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}
// low = 0, high = n-1 intially
void mergeSort(vector<int> &arr, int low, int high) {
  if (low >= high) return;
  int mid = (low + high) / 2;
  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}
// at every step n operations(comparisons)
// total steps log2(n)
// time complexity: O(nlog2(n))
// space complexity: O(n)

// Best   Average  Worst    Memory	Stable
// nlogn	nlogn	   nlogn      n	     Yes