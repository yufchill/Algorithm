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
  bool isValidBST(TreeNode *root, long long left = LLONG_MIN,
                  long long right = LLONG_MAX) {
    if (!root) return true;
    long long val = root->val;
    return val > left && val < right && isValidBST(root->left, left, val) &&
           isValidBST(root->right, val, right);
  }
};