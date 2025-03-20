#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  void remove_space(string &s) {
    int slow = 0, n = s.size();
    for (int fast = 0; fast < n; fast++) {
      if (s[fast] != ' ') {
        if (slow != 0) s[slow++] = ' ';
        while (fast < n && s[fast] != ' ') {
          s[slow++] = s[fast++];
        }
      }
    }
    s.resize(slow);
  }
  void reverse(string &s, int l, int r) {
    while (l < r) {
      swap(s[l++], s[r--]);
    }
  }

 public:
  string reverseWords(string s) {
    remove_space(s);
    reverse(s, 0, s.size() - 1);
    int left = 0;
    for (int right = 0; right < s.size(); right++) {
      if (s[right] == ' ') {
        reverse(s, left, right - 1);
        left = right + 1;
      }
    }
    reverse(s, left, s.size() - 1);
    return s;
  }
};