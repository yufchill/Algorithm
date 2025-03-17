#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> ans;
    for (auto& num : nums2) {
      if (set1.count(num)) {
        ans.insert(num);
      }
    }
    return vector<int>(ans.begin(), ans.end());
  }
};