#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> ans(m * n);
    int idx = 0;
    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;
    while (left <= right && top <= bottom) {
      for (int i = left; i <= right; i++) {
        ans[idx++] = matrix[top][i];
      }
      top++;
      for (int i = top; i <= bottom; i++) {
        ans[idx++] = matrix[i][right];
      }
      right--;
      if (top > bottom) break;
      for (int i = right; i >= left; i--) {
        ans[idx++] = matrix[bottom][i];
      }
      bottom--;
      if (left > right) break;
      for (int i = bottom; i >= top; i--) {
        ans[idx++] = matrix[i][left];
      }
      left++;
    }
    return ans;
  }
};
