// https:  // www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/

// Stability is mainly essential when we have key-value pairs with duplicate
// keys possible (like people’s names as keys and their details as values). And
// we wish to sort these objects by keys.

// A sorting algorithm is said to be stable if two objects with equal keys
// appear in the same order in sorted output as they appear in the input data
// set

// Some Sorting Algorithms are stable by nature, such as
// Bubble Sort, Insertion Sort, Merge Sort, Count Sort, etc.
// Comparison-based stable sorts such as Merge Sort and Insertion Sort maintain
// stability by ensuring that Element A[j]  comes before A[i]  if and only if
// A[j] < A[i] , here i, j are indices, and i < j . The relative order is
// preserved if A[i] = A[j]  i.e. A[i] comes before A[j]

// Other non-comparison-based sorts such as Counting Sort maintain stability by
// ensuring that the Sorted Array is filled in reverse order so that elements
// with equivalent keys have the same relative position. Some sorts such as
// Radix Sort depend on another sort, with the only requirement that the other
// sort should be stable.

// Which sorting algorithms are unstable ? Quick Sort, Heap Sort etc., can be
// made stable by also taking the position of the elements into
// consideration.This change may be done in a way that does not compromise a lot
// on the performance and takes some extra space, possibly \theta(n).

// Can we make any sorting algorithm stable
// Any given sorting algorithm which is not stable can be modified to be
// stable. There can be algorithm-specific ways to make it stable, but in
// general, any comparison-based sorting algorithm which is not stable by
// nature can be modified to be stable by changing the key comparison
// operation so that the comparison of two keys considers position as a
// factor for objects with equal keys.