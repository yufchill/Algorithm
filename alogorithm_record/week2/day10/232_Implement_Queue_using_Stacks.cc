#include <bits/stdc++.h>
using namespace std;

class MyQueue {
 private:
  stack<int> st1, st2;

 public:
  MyQueue() {}

  void push(int x) {
    st1.push(x);
    return;
  }

  int pop() {
    if (st2.empty()) {
      while (!st1.empty()) {
        int temp = st1.top();
        st1.pop();
        st2.push(temp);
      }
    }
    int res = st2.top();
    st2.pop();
    return res;
  }

  int peek() {
    int num = pop();
    st2.push(num);
    return num;
  }

  bool empty() { return st1.empty() && st2.empty(); }
};