#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Method 1:
ListNode *findMiddle(ListNode *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }

  ListNode *temp = head;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  int mid = count / 2;
  temp = head;
  while (mid--) {
    temp = temp->next;
  }
  return temp;
}
// TC: O(N)

class Solution {
 public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};
// TC:O(N/2)