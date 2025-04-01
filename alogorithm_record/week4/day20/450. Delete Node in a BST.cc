#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    if (key == root->val) {
      TreeNode* del = root;
      if (root->left == root->right) {
        root = nullptr;
      } else if (root->left && !root->right) {
        root = root->left;
      } else if (!root->left && root->right) {
        root = root->right;
      } else {
        TreeNode* temp = root->right;
        while (temp->left) {
          temp = temp->left;
        }
        temp->left = root->left;
        root->left = nullptr;
        root = root->right;
      }
      delete del;
      return root;
    }
    if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      root->left = deleteNode(root->left, key);
    }
    return root;
  }
};
