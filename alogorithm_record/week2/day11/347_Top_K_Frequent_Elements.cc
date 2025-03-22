#include <bits/stdc++.h>
using namespace std;
// class Solution {
//   public:
//    vector<int> topKFrequent(vector<int>& nums, int k) {
//      unordered_map<int, int> mp;
//      for (auto& num : nums) mp[num]++;
//      auto cmp = [](const pair<int, int> p1, const pair<int, int> p2) {
//        return p1.second > p2.second;
//      };
//      priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(
//          cmp);
//      for (auto& entry : mp) {
//        q.push(entry);
//        if (q.size() == k + 1) {
//          q.pop();
//        }
//      }
//      vector<int> ans;
//      while (!q.empty()) {
//        ans.push_back(q.top().first);
//        q.pop();
//      }
//      return ans;
//    }
//  };
class Solution {
  void quick_sort(vector<pair<int, int>>& nums, int left, int right, int k) {
    if (left >= right) return;
    int x = nums[left + right >> 1].second;
    int i = left - 1, j = right + 1;
    while (i < j) {
      while (nums[++i].second > x);
      while (nums[--j].second < x);
      if (i < j) swap(nums[i], nums[j]);
    }
    if (k < j - left + 1) {
      quick_sort(nums, left, j, k);
    } else if (k > j - left + 1) {
      quick_sort(nums, j + 1, right, k - (j - left + 1));
    } else {
      return;
    }
  }

 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (auto& num : nums) mp[num]++;
    vector<pair<int, int>> vec(mp.begin(), mp.end());
    quick_sort(vec, 0, vec.size() - 1, k);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
      ans.push_back(vec[i].first);
    }
    return ans;
  }
};
