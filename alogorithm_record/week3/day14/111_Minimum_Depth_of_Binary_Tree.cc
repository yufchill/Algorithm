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
  int dfs(TreeNode *node) {
    if (!node->left && !node->right) return 1;
    int left = INT_MAX, right = INT_MAX;
    if (node->left) {
      left = dfs(node->left);
    }
    if (node->right) {
      right = dfs(node->right);
    }
    return min(left, right) + 1;
  }

 public:
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    return dfs(root);
  }
};