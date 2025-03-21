#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string removeDuplicates(string s) {
    string ans;
    for (auto &c : s) {
      if (ans.empty() || c != ans.back()) {
        ans += c;
      } else {
        while (!ans.empty() && c == ans.back()) {
          ans.pop_back();
        }
      }
    }
    return ans;
  }
};