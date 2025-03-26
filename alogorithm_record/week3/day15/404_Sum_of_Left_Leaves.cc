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
  int dfs(TreeNode *root, bool flag = false) {
    if (!root) return 0;
    int res = 0;
    if (flag && !root->left && !root->right) {
      res += root->val;
    }
    return res + dfs(root->left, true) + dfs(root->right, false);
  }

 public:
  int sumOfLeftLeaves(TreeNode *root) { return dfs(root); }
};