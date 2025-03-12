#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    int l = 0, r = n - 1;
    int index = 0;
    while (l <= r) {
      int left = nums[l] * nums[l];
      int right = nums[r] * nums[r];
      if (left > right) {
        res[index++] = left;
        l++;
      } else {
        res[index++] = right;
        r--;
      }
    }
    reverse(res.begin(), res.end());
    return res;
  }
};