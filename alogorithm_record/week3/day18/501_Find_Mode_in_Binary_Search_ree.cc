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
  int max_cnt = 0;
  int cur_cnt = 0;
  TreeNode *pre;
  vector<int> ans;
  void dfs(TreeNode *cur) {
    if (!cur) return;
    dfs(cur->left);
    if (!pre) {
      cur_cnt = 1;
    } else if (pre->val == cur->val) {
      cur_cnt++;
    } else {
      cur_cnt = 1;
    }
    pre = cur;
    if (cur_cnt == max_cnt) {
      ans.push_back(cur->val);
    }
    if (cur_cnt > max_cnt) {
      max_cnt = cur_cnt;
      ans.clear();
      ans.push_back(cur->val);
    }
    dfs(cur->right);
  }

 public:
  vector<int> findMode(TreeNode *root) {
    dfs(root);
    return ans;
  }
};