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
  int sum = 0;
  void dfs(TreeNode *root) {
    if (!root) return;
    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
  }

 public:
  TreeNode *convertBST(TreeNode *root) {
    dfs(root);
    return root;
  }
};