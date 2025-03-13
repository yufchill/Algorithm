#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, cur = 0;
    int ans = INT_MAX;
    for (int right = 0; right < nums.size(); right++) {
      cur += nums[right];
      while (cur >= target) {
        ans = min(ans, right - left + 1);
        cur -= nums[left++];
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
