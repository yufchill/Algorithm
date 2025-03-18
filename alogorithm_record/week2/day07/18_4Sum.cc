#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      if (i && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int l = j + 1, r = n - 1;
        while (l < r) {
          long sum = (long)nums[i] + nums[j] + nums[l] + nums[r];
          if (sum < target) {
            l++;
          } else if (sum > target) {
            r--;
          } else {
            ans.push_back({nums[i], nums[j], nums[l], nums[r]});
            while (l < r && nums[l] == nums[l + 1]) l++;
            while (l < r && nums[r] == nums[r - 1]) r--;
            l++;
            r--;
          }
        }
      }
    }
    return ans;
  }
};