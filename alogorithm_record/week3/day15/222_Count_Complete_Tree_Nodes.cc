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
  int countNodes(TreeNode *root) {
    if (!root) return 0;
    int left = 0, right = 0;
    TreeNode *cur = root;
    while (cur) {
      cur = cur->left;
      left++;
    }
    cur = root;
    while (cur) {
      cur = cur->right;
      right++;
    }
    if (left == right) {
      return (2 << left) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};