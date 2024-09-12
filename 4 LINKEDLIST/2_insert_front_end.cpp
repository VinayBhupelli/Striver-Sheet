#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

class Solution {
 public:
  // Function to insert a node at the beginning of the linked list.
  Node *insertAtBegining(Node *head, int x) {
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
    return head;
  }
  // Time Complexity: O(1) for inserting the new head of the linked list and
  // O(N) for printing the linked list. Space Complexity: O(1), as we have not
  // used any extra space. Function to insert a node at the end of the linked
  // list.

  Node *insertAtEnd(Node *head, int x) {
    Node *newNode = new Node(x);
    Node *temp = head;
    if (temp == NULL) return newNode;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
    temp = newNode;
    return head;
  }
};