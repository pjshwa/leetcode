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
  vector<int> L, R; double target;

  void dfs(TreeNode* node) {
    if (!node) return;
    dfs(node->left);
    if (node->val <= target) L.push_back(node->val);
    else R.push_back(node->val);
    dfs(node->right);
  }

public:
  vector<int> closestKValues(TreeNode* root, double target, int k) {
    this->target = target;
    dfs(root);

    reverse(R.begin(), R.end());
    vector<int> res;
    while (k--) {
      if (L.empty()) res.push_back(R.back()), R.pop_back();
      else if (R.empty() || abs(L.back() - target) < abs(R.back() - target)) res.push_back(L.back()), L.pop_back();
      else res.push_back(R.back()), R.pop_back();
    }
    return res;
  }
};
