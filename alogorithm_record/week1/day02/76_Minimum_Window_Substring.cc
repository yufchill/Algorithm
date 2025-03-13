#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  string minWindow(string s, string t) {
    int sub_size = t.size();
    int n = s.size();
    if (n < sub_size) return "";
    unordered_map<char, int> sub, mp;
    for (auto &c : t) sub[c]++;
    int left = 0, cur = 0;
    int index = -1, len = INT_MAX;
    for (int right = 0; right < n; right++) {
      mp[s[right]]++;
      if (mp[s[right]] <= sub[s[right]]) cur++;
      while (cur == sub_size) {
        int cur_len = right - left + 1;
        if (len > cur_len) {
          len = cur_len;
          index = left;
        }
        mp[s[left]]--;
        if (mp[s[left]] < sub[s[left]]) {
          cur--;
        }
        left++;
      }
    }
    return index == -1 ? "" : s.substr(index, len);
  }
};