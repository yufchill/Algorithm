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
  bool isSymmetric(TreeNode *root) {
    stack<TreeNode *> st;
    if (!root->left || !root->right) return root->left == root->right;
    st.push(root->left);
    st.push(root->right);
    while (!st.empty()) {
      TreeNode *node1 = st.top();
      st.pop();
      TreeNode *node2 = st.top();
      st.pop();
      if (node1->val != node2->val) {
        return false;
      }
      if (!node1->left || !node2->right) {
        if (!(!node1->left && !node2->right)) {
          return false;
        }
      }
      if (!node2->left || !node1->right) {
        if (!(!node2->left && !node1->right)) {
          return false;
        }
      }
      if (node1->left) st.push(node1->left);
      if (node2->right) st.push(node2->right);
      if (node1->right) st.push(node1->right);
      if (node2->left) st.push(node2->left);
    }
    return true;
  }
};