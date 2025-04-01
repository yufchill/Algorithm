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
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.empty()) return nullptr;
    int mid = nums.size() / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin() + mid + 1, nums.end());
    TreeNode *new_node = new TreeNode(nums[mid]);
    new_node->left = sortedArrayToBST(left);
    new_node->right = sortedArrayToBST(right);
    return new_node;
  }
};