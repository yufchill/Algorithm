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
  vector<vector<int>> ans;
  void dfs(TreeNode *root, int targetSum, int cur, vector<int> path) {
    if (!root) return;
    cur += root->val;
    path.push_back(root->val);
    if (root->left == root->right && cur == targetSum) {
      ans.push_back(path);
      return;
    }
    dfs(root->left, targetSum, cur, path);
    dfs(root->right, targetSum, cur, path);
  }

 public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    dfs(root, targetSum, 0, {});
    return ans;
  }
};