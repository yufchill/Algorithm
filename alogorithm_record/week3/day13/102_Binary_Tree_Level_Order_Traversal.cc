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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    deque<TreeNode *> q;
    if (root) q.push_back(root);
    while (!q.empty()) {
      int n = q.size();
      vector<int> temp;
      for (int i = 0; i < n; ++i) {
        TreeNode *cur = q.front();
        q.pop_front();
        temp.push_back(cur->val);
        if (cur->left) q.push_back(cur->left);
        if (cur->right) q.push_back(cur->right);
      }
      ans.push_back(temp);
    }
    return ans;
  }
};