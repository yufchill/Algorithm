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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *cur = root;
    TreeNode *last_view = nullptr;
    while (cur || !st.empty()) {
      while (cur) {
        st.push(cur);
        cur = cur->left;
      }
      cur = st.top();
      if (cur->right && cur->right != last_view) {
        cur = cur->right;
      } else {
        st.pop();
        ans.push_back(cur->val);
        last_view = cur;
        cur = nullptr;
      }
    }
    return ans;
  }
};