#include <bits/stdc++.h>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
 private:
  ListNode* dummy_head;
  int size;

 public:
  MyLinkedList() : dummy_head(new ListNode(0, nullptr)), size(0) {}

  int get(int index) {
    if (index < 0 || index >= size) return -1;
    ListNode* cur = dummy_head;
    for (int i = 0; i <= index; i++) {
      cur = cur->next;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    ListNode* node = new ListNode(val, nullptr);
    node->next = dummy_head->next;
    dummy_head->next = node;
    size++;
  }

  void addAtTail(int val) {
    ListNode* node = new ListNode(val, nullptr);
    ListNode* cur = dummy_head;
    for (int i = 0; i < size; i++) {
      cur = cur->next;
    }
    cur->next = node;
    size++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size) return;
    ListNode* node = new ListNode(val, nullptr);
    ListNode* cur = dummy_head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return;
    ListNode* cur = dummy_head;
    for (int i = 0; i < index; i++) {
      cur = cur->next;
    }
    ListNode* del = cur->next;
    cur->next = del->next;
    delete del;
    size--;
  }
};
