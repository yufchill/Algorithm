#include <bits/stdc++.h>
using namespace std;

class MyStack {
 private:
  queue<int> q;
  int size = 0;

 public:
  MyStack() {}

  void push(int x) {
    q.push(x);
    size++;
  }

  int pop() {
    int n = size - 1;
    while (n--) {
      int temp = q.front();
      q.pop();
      q.push(temp);
    }
    int res = q.front();
    q.pop();
    size--;
    return res;
  }

  int top() {
    int res = pop();
    push(res);
    return res;
  }

  bool empty() { return size == 0; }
};
