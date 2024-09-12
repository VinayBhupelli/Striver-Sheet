// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;

// Method 1: Recursive
// intially n is N
void bubble_sort(int arr[], int n) {
  if (n == 1) return;
  int didSwap = 0;
  for (int j = 0; j <= n - 2; j++) {
    if (arr[j] > arr[j + 1]) {
      swap(arr[j], arr[j + 1]);
      didSwap = 1;
    }
  }
  if (didSwap == 0) return;
  bubble_sort(arr, n - 1);
}

// Method 2: Itrative
// An optimized version of Bubble Sort
// Adding Swapped or not variable in it
void bubbleSort(int arr[], int n) {
  for (int i = n - 1; i >= 0; i--) {
    bool swapped = false;
    for (int j = 0; j <= i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
    // If no two elements were swapped
    // by inner loop, then break
    if (swapped == false) break;
  }
}
// Everytime we bring the largest element to the ith index

// Best Average   Worst   Memory	Stable
// n	   n^{2}	  n^{2}	  1	    Yes
// Exchanging