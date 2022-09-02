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
  double s[10000], z[10000];

  void dfs(TreeNode* v, int l) {
    s[l] += v->val;
    z[l]++;
    if (v->left) dfs(v->left, l + 1);
    if (v->right) dfs(v->right, l + 1);
  }

public:
  vector<double> averageOfLevels(TreeNode* root) {
    memset(s, 0, sizeof(s));
    memset(z, 0, sizeof(z));
    dfs(root, 0);
    
    vector<double> ans;
    for (int i = 0;; i++) {
      if (!z[i]) break;
      ans.push_back(s[i] / z[i]);
    }
    return ans;
  }
};
