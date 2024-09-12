#include <bits/stdc++.h>
using namespace std;
// Recursive Selection sort : Headache
int minIndex(int a[], int i, int j) {
  if (i == j) return i;
  int k = minIndex(a, i + 1, j);
  return (a[i] < a[k]) ? i : k;
}
void recurSelectionSort(int a[], int n, int index = 0) {
  if (index == n) return;
  int k = minIndex(a, index, n - 1);
  if (k != index) swap(a[k], a[index]);
  recurSelectionSort(a, n, index + 1);
}
// TC: O(n^2)
// SC: O(n)

// Function for Selection sort
void selectionSort(int arr[], int n) {
  int i, j, min_idx;
  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) min_idx = j;
    }
    if (min_idx != i) swap(arr[min_idx], arr[i]);
  }
}
// Stable Selection sort
void stableSelectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++)
      if (a[min] > a[j]) min = j;

    int key = a[min];
    // Shift left all elements by one.
    for (int k = min; k > i; k--) a[k] = a[k - 1];
    // Store the key at its right position.
    a[i] = key;
  }
}
//  Name	 Best   Average    Worst     Memory   Stable
// Selection n^{2}  n^{2}	   n^{2}	   1	  No

// Optimised Selection Sort
void solve(vector<int>& arr, int n) {
  for (int i = 0, j = n - 1; i < j; i++, j--) {
    int min = arr[i], max = arr[i];
    int min_i = i, max_i = i;
    for (int k = i; k <= j; k++) {
      if (arr[k] > max) {
        max = arr[k];
        max_i = k;
      } else if (arr[k] < min) {
        min = arr[k];
        min_i = k;
      }
    }
    swap(arr[i], arr[min_i]);
    // what if we swapped the max
    if (arr[min_i] == max)
      swap(arr[min_i], arr[j]);
    else
      swap(arr[max_i], arr[j]);
  }
}
// TC: O(n^2)
// SC: O(1)

// https://www.geeksforgeeks.org/iterative-selection-sort-for-linked-list/?ref=lbp