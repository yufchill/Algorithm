#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<char, char> mp{{')', '('}, {'}', '{'}, {']', '['}};
  unordered_set<char> set{'(', '{', '['};

 public:
  bool isValid(string s) {
    stack<char> st;
    for (auto &c : s) {
      if (set.count(c)) {
        st.push(c);
      } else {
        if (st.empty() || st.top() != mp[c]) {
          return false;
        }
        st.pop();
      }
    }
    return st.empty();
  }
};