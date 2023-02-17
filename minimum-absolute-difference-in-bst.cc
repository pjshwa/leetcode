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
  vector<int> R;

  void dfs(TreeNode* node) {
    if (node == nullptr) return;
    R.push_back(node->val);
    dfs(node->left);
    dfs(node->right);
  }

public:
  int getMinimumDifference(TreeNode* root) {
    dfs(root);

    sort(R.begin(), R.end());
    int n = R.size(), ans = 0x3f3f3f3f;
    for (int i = 1; i < n; i++) ans = min(ans, R[i] - R[i - 1]);
    return ans;
  }
};
