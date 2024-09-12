#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
// Method 1:
ListNode* sortLL(ListNode* head) {
  vector<int> arr;
  ListNode* temp = head;
  while (temp != NULL) {
    arr.push_back(temp->val);
    temp = temp->next;
  }
  sort(arr.begin(), arr.end());
  temp = head;
  for (int i = 0; i < arr.size(); i++) {
    temp->val = arr[i];
    temp = temp->next;
  }
  return head;
}
// Method 2:
class Solution {
 public:
  // finding the middle element
  ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
  // Merging the linked list
  ListNode* Merge(ListNode* head1, ListNode* head2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    while (head1 != NULL && head2 != NULL) {
      if (head1->val < head2->val) {
        temp->next = head1;
        temp = head1;
        head1 = head1->next;
      } else {
        temp->next = head2;
        temp = head2;
        head2 = head2->next;
      }
    }
    if (head1 != NULL) temp->next = head1;
    if (head2 != NULL) temp->next = head2;
    return dummy->next;
  }
  ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* middle = middleNode(head);
    ListNode* head1 = head;
    ListNode* head2 = middle->next;
    middle->next = NULL;

    head1 = sortList(head1);
    head2 = sortList(head2);

    return Merge(head1, head2);
  }
};