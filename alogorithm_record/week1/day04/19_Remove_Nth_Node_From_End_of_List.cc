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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy_node = ListNode(0, head);
    ListNode* slow = &dummy_node;
    ListNode* fast = &dummy_node;
    while (n--) fast = fast->next;
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return dummy_node.next;
  }
};