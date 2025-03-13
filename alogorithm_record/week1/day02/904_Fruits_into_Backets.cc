#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> mp;
    int left = 0, cur = 0;
    int ans = INT_MIN;
    for (int right = 0; right < fruits.size(); right++) {
      mp[fruits[right]]++;
      if (mp[fruits[right]] == 1) cur++;
      while (cur == 3) {
        mp[fruits[left]]--;
        if (mp[fruits[left]] == 0) cur--;
        left++;
      }
      ans = max(ans, right - left + 1);
    }
    return ans;
  }
};