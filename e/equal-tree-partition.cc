/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  int total, flag = 0, ans = 0;
  TreeNode* root;

  int f(TreeNode* node) {
    if (node == nullptr) return 0;
    int ret = node->val + f(node->left) + f(node->right);
    ans |= (node != root && flag == 1 && ret * 2 == total);
    return ret;
  }

public:
  bool checkEqualTree(TreeNode* root) {
    this->root = root; total = f(root);
    flag = 1; f(root);
    return ans;
  }
};
