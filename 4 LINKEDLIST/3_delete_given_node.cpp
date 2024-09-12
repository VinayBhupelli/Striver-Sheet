#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// O(1) time to delete any element if the node pointer available
class Solution {
 public:
  void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};
// Delete the last node
ListNode* deleteTail(ListNode* head) {
  // If the list is empty or has only one node, return NULL
  if (head == NULL || head->next == NULL) return NULL;
  // Initialize a temporary pointer to traverse the list
  ListNode* temp = head;
  // Traverse to the second last node in the list
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  // Delete the last node
  delete temp->next;
  // Set the next of the second last node to nullptr, effectively removing the
  // last node
  temp->next = nullptr;
  // Return the head of the modified list
  return head;
}
// TC : O(N)
// SC : O(1)
// Note: In the case of languages like Java, Python, and Javascript, there is no
// need for the deletion of objects or nodes because these have an automatic
// garbage collection mechanism that automatically identifies and reclaims
// memory that is no longer in use.