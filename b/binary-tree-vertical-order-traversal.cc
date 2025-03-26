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
  vector<int> B[250];

  void dfs(TreeNode* node, int pos) {
    if (node == nullptr) return;
    B[pos + 100].push_back(node->val);
    dfs(node->left, pos - 1);
    dfs(node->right, pos + 1);
  }

public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    if (root == nullptr) return {};

    queue<pair<TreeNode*, int>> Q;
    Q.push({root, 100});
    while (!Q.empty()) {
      auto [node, pos] = Q.front(); Q.pop();
      B[pos].push_back(node->val);
      if (node->left) Q.push({node->left, pos - 1});
      if (node->right) Q.push({node->right, pos + 1});
    }

    vector<vector<int>> ans;
    for (int i = 0; i < 250; ++i) {
      if (!B[i].empty()) ans.push_back(B[i]);
    }
    return ans;
  }
};
