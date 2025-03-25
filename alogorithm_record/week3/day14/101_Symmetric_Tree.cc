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
  bool dfs(TreeNode *node1, TreeNode *node2) {
    if (!node1 || !node2) {
      return node1 == node2;
    }
    return node1->val == node2->val && dfs(node1->left, node2->right) &&
           dfs(node1->right, node2->left);
  }

 public:
  bool isSymmetric(TreeNode *root) { return dfs(root->left, root->right); }
};