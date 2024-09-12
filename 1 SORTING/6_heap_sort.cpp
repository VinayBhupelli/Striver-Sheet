#include <bits/stdc++.h>
using namespace std;
// Heap sort is a comparison-based sorting technique based on Binary Heap Data
// Structure

//  It can be seen as an optimization over selection sort where we first find
//  the max (or min) element and swap it with the last (or first)

// In Heap Sort, we use Binary Heap so that we can quickly find and move the max
// element (In O(Log n) instead of O(n)) and hence achieve the O(n Log n) time
// complexity. Here it is max Heap
void heapify(int a[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && a[left] > a[largest]) largest = left;
  if (right < n && a[right] > a[largest]) largest = right;
  if (largest != i) {
    swap(a[i], a[largest]);
    heapify(a, n, largest);
  }
}
void heap_sort(int a[], int n) {
  // this just make sure that every parent is greater than child
  for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
  // this makes the sorting
  for (int i = n - 1; i >= 0; i--) {
    // place the max element at the end
    swap(a[0], a[i]);
    // heapify the root element to maintain heap property
    heapify(a, i, 0);
  }
}
// Best Case  	Average Case  	Worst Case 	Memory	Stable
// n log n	    n log n	        n log n	      1      No
// SC: O(logn) auxiliary stack space

// in place algorithm
// Its typical implementation is not stable but can be made stable
// Typically 2-3 times slower than well-implemented QuickSort. The reason for
// slowness is a lack of locality of reference.