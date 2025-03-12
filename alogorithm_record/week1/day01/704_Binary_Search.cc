#include <bits/stdc++.h>
using namespace std;
class Solution {
  int lower_bound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return left;
  }

 public:
  int search(vector<int>& nums, int target) {
    int res = lower_bound(nums, target);
    return res < nums.size() && nums[res] == target ? res : -1;
  }
};