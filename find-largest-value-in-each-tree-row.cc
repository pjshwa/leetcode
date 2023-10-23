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

const int MAX = 1e4;

class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    vector<int> maxLevels(MAX + 1, INT_MIN); int maxl = -1;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
      auto [node, level] = q.front(); q.pop();
      if (node == nullptr) continue;
      maxLevels[level] = max(maxLevels[level], node->val);
      maxl = max(maxl, level);
      q.push({node->left, level + 1});
      q.push({node->right, level + 1});
    }

    vector<int> ans;
    for (int i = 0; i <= maxl; ++i) {
      ans.push_back(maxLevels[i]);
    }
    return ans;
  }
};
