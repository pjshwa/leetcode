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
  map<int, int> tal;
  void dfs(TreeNode* root) {
    if (root == nullptr) return;
    tal[root->val]++;
    dfs(root->left);
    dfs(root->right);
  }

public:
  vector<int> findMode(TreeNode* root) {
    dfs(root);

    int mode = 0;
    for (auto& [k, v] : tal) {
      if (v > mode) mode = v;
    }

    vector<int> ans;
    for (auto& [k, v] : tal) {
      if (v == mode) ans.push_back(k);
    }
    return ans;
  }
};
