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
  ListNode* removeElements(ListNode* head, int val) {
    auto dummy_node = ListNode(0, head);
    auto cur = &dummy_node;
    while (cur->next) {
      auto node = cur->next;
      if (node->val == val) {
        cur->next = node->next;
        delete node;
      } else {
        cur = cur->next;
      }
    }
    return dummy_node.next;
  }
};