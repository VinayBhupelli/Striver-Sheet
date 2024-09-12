// Arrays Fixed size data structure
// linked list variable sized data structure

// linear data structure with chains connected

// array elements are stored in contiguous memory
// linked list elements are not stored in contiguous memory

// inserting in array the next element need to be empty
// where as in linked list it is not required to be empty

#include <bits/stdc++.h>
using namespace std;

class Node {
 public:       // access modifier
  int data;    // the data value
  Node* next;  // the pointer to the next value
 public:
  // constructor
  Node(int data1, Node* next1) {
    data = data1;  // Initialize data with the provided value
    next = next1;  // Initialize next with the provided
  }
  Node(int data1) {
    data = data1;    // Initialize data with the provided value
    next = nullptr;  // Initialize next as null since it's the end of the list
  }
};
int main() {
  vector<int> arr = {2, 5, 8, 7};
  Node* y = new Node(arr[0]);
  cout << y << '\n';        // returns the memory value
  cout << y->data << '\n';  // returns the data stored at that memory point
}

// we are storing integers that consume 4 Bytes for every int, whereas in a
// linked list, we are storing data and a pointer at every node, so the memory
// used up will depend on the configuration of the system.

// Dynamic memory allocation relies on linked lists to manage and allocate
// memory blocks efficiently.

// Web browsers use linked lists to store the browsing history of the user,
// allowing them to easily navigate between previously visited pages using the
// forward and backward buttons.

// A significant characteristic of singly linked lists is their unidirectional
// nature, allowing traversal in only one direction

// Doubly Linked Lists,  as the name suggests, take the concept of 2-way
// traversal by introducing two pointers in each node. This enables seamless
// traversal in both directions, making them a valuable tool for various
// advanced data structure applications.