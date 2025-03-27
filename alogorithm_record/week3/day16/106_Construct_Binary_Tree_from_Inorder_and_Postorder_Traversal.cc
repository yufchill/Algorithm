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
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.empty()) return nullptr;
    int left_size = find(inorder.begin(), inorder.end(), postorder.back()) -
                    inorder.begin();
    vector<int> in1(inorder.begin(), inorder.begin() + left_size);
    vector<int> in2(inorder.begin() + left_size + 1, inorder.end());
    vector<int> post1(postorder.begin(), postorder.begin() + left_size);
    vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);
    TreeNode* left = buildTree(in1, post1);
    TreeNode* right = buildTree(in2, post2);
    return new TreeNode(postorder.back(), left, right);
  }
};