#include <bits/stdc++.h>
using namespace std;

// 1. Select an element in each iteration from the unsorted array(using a loop)
// 2. Place it in its corresponding position in the sorted part and shift the
// remaining elements accordingly(using an inner loop and swapping)
// 3. The “inner while loop” basically shifts the elements using swapping.

// Method 1: Recursive
void insertionSort(int arr[], int i, int n) {
  if (i == n) return;
  for (int i = 1; i < i; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
  insertionSort(arr, i + 1, n);
}

// insertion sort
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

// Best Average Worst Memory  Stable
// n	n^{2}	n^{2}	1	  Yes