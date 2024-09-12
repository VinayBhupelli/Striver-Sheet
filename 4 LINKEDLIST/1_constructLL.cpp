#include <bits/stdc++.h>
using namespace std;
class Node {
 public:
  int data;
  Node *next;

  // Default constructor
  Node() {
    data = 0;
    next = NULL;
  }

  // Parameterised Constructor
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};
class Solution {
 public:
  Node *constructLL(vector<int> &arr) {
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i < arr.size(); i++) {
      Node *newNode = new Node(arr[i]);
      temp->next = newNode;
      temp = newNode;
    }
    return head;
  }
};