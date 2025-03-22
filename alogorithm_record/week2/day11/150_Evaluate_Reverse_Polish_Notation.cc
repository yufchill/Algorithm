#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> st;
    for (auto& token : tokens) {
      if (token == "+" or token == "-" or token == "*" or token == "/") {
        int num2 = st.top();
        st.pop();
        int num1 = st.top();
        st.pop();
        if (token == "+") st.push(num1 + num2);
        if (token == "-") st.push(num1 - num2);
        if (token == "*") st.push(num1 * num2);
        if (token == "/") st.push(num1 / num2);
      } else {
        st.push(stoi(token));
      }
    }
    return st.top();
  }
};