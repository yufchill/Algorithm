#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string reverseStr(string s, int k) {
    int n = s.size();
    int index = 0;
    while (n >= 2 * k) {
      n -= 2 * k;
      reverse(s.begin() + index, s.begin() + index + k);
      index += 2 * k;
    }
    if (n >= k) {
      reverse(s.begin() + index, s.begin() + index + k);
    } else {
      reverse(s.begin() + index, s.end());
    }
    return s;
  }
};