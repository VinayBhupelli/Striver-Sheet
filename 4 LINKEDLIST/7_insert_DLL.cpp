#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) {
    data = x;
    next = prev = NULL;
  }
};

// Function to insert a new node at given position in doubly linked list.
void addNode(Node *head, int pos, int data) {
  Node *newNode = new Node(data);
  Node *temp = head;
  while (pos--) {
    temp = temp->next;
  }
  if (temp->next == NULL) {
    temp->next = newNode;
    newNode->prev = temp;
  } else {
    newNode->next = temp->next;
    temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;
  }
}
// TC: O(pos)
// SC: O(1)

// Insert at the end of doubly linked list
Node *insertAtTail(Node *head, int k) {
  // Create a new node with data 'k'
  Node *newNode = new Node(k);
  if (head == nullptr) return newNode;

  Node *tail = head;
  while (tail->next != nullptr) tail = tail->next;

  // Connect the new node to the last node in the list
  tail->next = newNode;
  newNode->prev = tail;

  return head;
}
// TC: O(N)
// SC: O(1)