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
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    if (nums.empty()) return nullptr;
    auto it = max_element(nums.begin(), nums.end());
    int left_size = it - nums.begin();
    TreeNode *node = new TreeNode(*it);
    vector<int> left = vector<int>(nums.begin(), nums.begin() + left_size);
    vector<int> right = vector<int>(nums.begin() + left_size + 1, nums.end());
    node->left = constructMaximumBinaryTree(left);
    node->right = constructMaximumBinaryTree(right);
    return node;
  }
};