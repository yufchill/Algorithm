#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    int cur = 1;
    vector<vector<int>> ans(n, vector<int>(n));
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1;
    while (left <= right && top <= bottom) {
      for (int i = left; i <= right; i++) {
        ans[top][i] = cur++;
      }
      top++;

      for (int i = top; i <= bottom; i++) {
        ans[i][right] = cur++;
      }
      right--;

      if (bottom < top) break;
      for (int i = right; i >= left; i--) {
        ans[bottom][i] = cur++;
      }
      bottom--;

      if (right < left) break;
      for (int i = bottom; i >= top; i--) {
        ans[i][left] = cur++;
      }
      left++;
    }
    return ans;
  }
};