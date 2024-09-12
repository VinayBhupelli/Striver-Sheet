#include <bits/stdc++.h>
using namespace std;
// Divide and Conquer Algorithm
// But unlike Merge sort, this algorithm does not use any extra array for
// sorting(though it uses an auxiliary stack space). So, from that perspective,
// Quick sort is slightly better than Merge sort

int partition(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int i = low;
  int j = high;

  while (i < j) {
    // here equal-to is important
    while (arr[i] <= pivot && i <= high - 1) {
      i++;
    }

    while (arr[j] > pivot && j >= low + 1) {
      j--;
    }
    if (i < j) swap(arr[i], arr[j]);
  }
  // here is important
  swap(arr[low], arr[j]);
  return j;
}

void qs(vector<int> &arr, int low, int high) {
  if (low < high) return;

  int pIndex = partition(arr, low, high);
  qs(arr, low, pIndex - 1);
  qs(arr, pIndex + 1, high);
}

vector<int> quickSort(vector<int> arr) {
  qs(arr, 0, arr.size() - 1);
  return arr;
}
// 4 6 2 5 7 9 13
// Best Case  	Average Case  	Worst Case 	Memory	Stable
// nlog n	    n log n	         n^{2}       log n	  No

// Why worst case n^{2}
// The answer depends on the strategy for choosing pivot. In early versions of
// Quick Sort where the leftmost (or rightmost) element is chosen as a pivot,
// the worst occurs in the following cases.
// 1) Array is already sorted in the same order.
// 2) Array is already sorted in reverse order.
// 3) All elements are the same (a special case of cases 1 and 2)
// Since these cases are very common to use cases, the problem was easily solved
// by choosing either a random index for the pivot, choosing the middle index of
// the partition, or (especially for longer partitions) choosing the median of
// the first, middle and last element of the partition for the pivot. With these
// modifications, the worst case of Quicksort has fewer chances to occur, but a
// worst case can still occur if the input array is such that the maximum (or
// minimum) element is always chosen as the pivot. This is the worst case of
// quicksort where we choose highest element as pivot