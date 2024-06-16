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
public:
  vector<int> getLonelyNodes(TreeNode* root) {
    vector<int> ans;
    helper(root, ans);
    return ans;
  }

  void helper(TreeNode* node, vector<int>& ans) {
    if (node->left && node->right) {
      helper(node->left, ans);
      helper(node->right, ans);
    } else if (node->left) {
      ans.push_back(node->left->val);
      helper(node->left, ans);
    } else if (node->right) {
      ans.push_back(node->right->val);
      helper(node->right, ans);
    }
  }
};
