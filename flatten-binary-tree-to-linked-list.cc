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
  queue<TreeNode*> q;

  void dfs(TreeNode* node) {
    if (node == nullptr) return;
    q.push(node);
    dfs(node->left);
    dfs(node->right);
  }

public:
  void flatten(TreeNode* root) {
    dfs(root);
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      node->left = nullptr;
      if (q.empty()) node->right = nullptr;
      else node->right = q.front();
    }
  }
};
