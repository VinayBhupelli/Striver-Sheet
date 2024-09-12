#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
  Node(int x) {
    data = x;
    next = NULL;
    prev = NULL;
  }
};
class Solution {
 public:
  Node* removeDuplicates(struct Node* head) {
    Node* temp = head;
    while (temp != NULL) {
      Node* nextNode = temp->next;
      while (nextNode != NULL && nextNode->data == temp->data)
        nextNode = nextNode->next;
      temp->next = nextNode;
      if (nextNode != NULL) nextNode->prev = temp;
      temp = temp->next;
    }
    return head;
  }
};