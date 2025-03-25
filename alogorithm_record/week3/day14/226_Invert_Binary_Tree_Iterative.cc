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
  TreeNode *invertTree(TreeNode *root) {
    stack<TreeNode *> st;
    if (root) st.push(root);
    while (!st.empty()) {
      auto cur = st.top();
      st.pop();
      swap(cur->left, cur->right);
      if (cur->left) st.push(cur->left);
      if (cur->right) st.push(cur->right);
    }
    return root;
  }
};