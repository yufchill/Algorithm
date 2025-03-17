#include <bits/stdc++.h>
using namespace std;

class Solution {
 private:
  int get_next(int n) {
    int res = 0;
    while (n) {
      int x = n % 10;
      res += x * x;
      n /= 10;
    }
    return res;
  }

 public:
  bool isHappy(int n) {
    unordered_set<int> hash;
    while (n != 1) {
      if (hash.find(n) != hash.end()) return false;
      hash.insert(n);
      n = get_next(n);
    }
    return true;
  }
};