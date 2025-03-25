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
  void dfs(TreeNode *root) {
    if (!root) return;
    if (!root->left && !root->right) return;
    swap(root->left, root->right);
    dfs(root->left);
    dfs(root->right);
  }

 public:
  TreeNode *invertTree(TreeNode *root) {
    dfs(root);
    return root;
  }
};