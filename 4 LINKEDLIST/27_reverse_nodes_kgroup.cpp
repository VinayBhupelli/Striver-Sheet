#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* reverse(ListNode* temp) {
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* curr = temp;
    while (curr != NULL) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }
  ListNode* kthNode(ListNode* temp, int k) {
    k--;
    while (k-- && temp != NULL) temp = temp->next;
    return temp;
  }
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp != NULL) {
      // temp----------kthnode-nextnode
      ListNode* kthnode = kthNode(temp, k);
      if (kthnode == NULL) {
        if (prev != NULL) prev->next = temp;
        break;
      }
      ListNode* nextnode = kthnode->next;
      kthnode->next = NULL;
      reverse(temp);
      // kthnode---------temp
      if (temp == head)
        head = kthnode;
      else
        prev->next = kthnode;
      prev = temp;
      temp = nextnode;
    }
    return head;
  }
};
// TC: O(2N) reversing segments of K and finding the Kth node
// SC: O(1)