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
 public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *new_node = new TreeNode(val);
    if (!root) return new_node;
    TreeNode *pre = nullptr;
    TreeNode *cur = root;
    while (cur) {
      pre = cur;
      if (cur->val > val) {
        cur = cur->left;
      } else {
        cur = cur->right;
      }
    }
    if (pre->val > val) {
      pre->left = new_node;
    } else {
      pre->right = new_node;
    }
    return root;
  }
};