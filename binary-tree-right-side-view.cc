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
  vector<int> by_depth[101];

  void dfs(TreeNode* node, int d) {
    if (!node) return;
    by_depth[d].push_back(node->val);
    dfs(node->left, d + 1);
    dfs(node->right, d + 1);
  }
public:
  vector<int> rightSideView(TreeNode* root) {
    dfs(root, 0);
    vector<int> ans;
    for (int i = 0; i <= 100; i++) {
      if (by_depth[i].empty()) break;
      ans.push_back(by_depth[i].back());
    }
    return ans;
  }
};
