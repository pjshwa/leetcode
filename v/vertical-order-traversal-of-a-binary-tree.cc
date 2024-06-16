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
  map<int, vector<int>> u[2001];

  void dfs(TreeNode* v, int r, int c) {
    u[c + 1000][r].push_back(v->val);
    if (v->left) dfs(v->left, r + 1, c - 1);
    if (v->right) dfs(v->right, r + 1, c + 1);
  }
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    dfs(root, 0, 0);

    vector<vector<int>> ans;
    for (int i = 0; i <= 2000; i++) {
      vector<int> cur;
      for (auto& [k, vv] : u[i]) {
        sort(vv.begin(), vv.end());
        for (int e : vv) cur.push_back(e);
      }
      if (cur.size()) ans.push_back(cur);
    }
    return ans;
  }
};
