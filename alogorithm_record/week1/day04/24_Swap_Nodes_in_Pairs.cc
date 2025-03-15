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
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy_node = ListNode(0, head);
    ListNode* cur = &dummy_node;
    while (cur->next && cur->next->next) {
      auto node1 = cur->next;
      auto node2 = cur->next->next;
      node1->next = node2->next;
      cur->next = node2;
      node2->next = node1;
      cur = node1;
    }
    return dummy_node.next;
  }
};