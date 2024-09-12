#include <bits/stdc++.h>
using namespace std;
struct Node {
  int val;
  struct Node* next;
  struct Node* random;
  Node(int x) {
    val = x;
    next = NULL;
    random = NULL;
  }
};
// Method 1:
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> hm;
    Node* temp = head;
    while (temp != NULL) {
      hm[temp] = new Node(temp->val);
      temp = temp->next;
    }
    temp = head;
    while (temp != NULL) {
      Node* copyNode = hm[temp];
      copyNode->next = hm[temp->next];
      copyNode->random = hm[temp->random];
      temp = temp->next;
    }
    return hm[head];
  }
};
// TC: O(2N)
// SC:O(2N) mapping+new creation

// Method 2:
class Solution {
 public:
  Node* copyRandomList(Node* head) {
    // step 1 creating copy nodes
    Node* itr = head;
    Node* front = head;
    while (itr != NULL) {
      front = itr->next;
      Node* copy = new Node(itr->val);
      copy->next = front;
      itr->next = copy;
      itr = itr->next->next;
    }
    // step 2
    itr = head;
    while (itr != NULL) {
      if (itr->random != NULL) {
        itr->next->random = itr->random->next;
      }
      itr = itr->next->next;
    }
    // step 3
    Node* start = new Node(0);
    Node* copy = start;
    itr = head;
    while (itr != NULL) {
      front = itr->next->next;
      copy->next = itr->next;
      itr->next = front;
      copy = copy->next;
      itr = itr->next;
    }
    return start->next;
  }
};
// TC: O(3N)
// SC: O(N) only new nodes creation