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
  int max_depth = -1;
  int ans = 0;
  void dfs(TreeNode *root, int cur_depth) {
    if (!root) return;
    dfs(root->left, cur_depth + 1);
    dfs(root->right, cur_depth + 1);
    if (cur_depth > max_depth) {
      max_depth = cur_depth;
      ans = root->val;
    }
  }

 public:
  int findBottomLeftValue(TreeNode *root) {
    dfs(root, 0);
    return ans;
  }
};