#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> ss, tt;
    for (auto &c : s) ss[c]++;
    for (auto &c : t) tt[c]++;
    return ss == tt;
  }
};