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
bool isPalindrome(ListNode *head) {
  stack<int> st;
  ListNode *temp = head;
  while (temp != NULL) {
    st.push(temp->val);
    temp = temp->next;
  }
  temp = head;
  while (temp != NULL) {
    if (temp->val != st.top()) {
      return false;
    }
    st.pop();
    temp = temp->next;
  }
  return true;
}
// TC: O(N)
// SC: O(N)

// Method 2:
class Solution {
 public:
  bool isPalindrome(ListNode *head) {
    // finding the middle node of the list
    ListNode *slow = head, *fast = head, *prev, *temp;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    // slow will be the middle node of the list
    // reverse the second half of the list
    prev = slow, slow = slow->next, prev->next = NULL;
    while (slow) {
      temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    // start comparint the lists
    fast = head, slow = prev;
    while (slow) {
      if (fast->val != slow->val) return false;

      fast = fast->next;
      slow = slow->next;
    }
    return true;
  }
};
// TC: O(N)
// SC: O(1)