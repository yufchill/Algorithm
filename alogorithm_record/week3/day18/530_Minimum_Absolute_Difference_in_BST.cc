#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
  int ans = INT_MAX;
  TreeNode *pre = nullptr;
  void dfs(TreeNode *cur) {
    if (!cur) return;
    dfs(cur->left);
    if (pre) {
      ans = min(ans, abs(cur->val - pre->val));
    }
    pre = cur;
    dfs(cur->right);
  }

 public:
  int getMinimumDifference(TreeNode *root) {
    dfs(root);
    return ans;
  }
};