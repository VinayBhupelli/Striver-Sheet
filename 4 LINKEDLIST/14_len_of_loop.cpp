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
// Method 1:
int lengthOfLoop(Node *head) {
  unordered_map<Node *, int> visitedNodes;
  Node *temp = head;
  int timer = 0;
  while (temp != NULL) {
    if (visitedNodes.find(temp) != visitedNodes.end()) {
      int loopLength = timer - visitedNodes[temp];
      return loopLength;
    }
    visitedNodes[temp] = timer;
    temp = temp->next;
    timer++;
  }
  return 0;
}

// Method 2:
int countNodesinLoop(struct Node *head) {
  if (head == NULL || head->next == NULL) return NULL;

  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) break;
  }
  if (slow != fast) return 0;
  int len = 1;
  while (slow != fast) {
    len++;
    slow = slow->next;
  }
  return len;
}