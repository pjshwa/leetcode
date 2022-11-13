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

using pii = pair<int, int>;

class Solution {
  vector<int> by_level[100'001];

  void dfs(TreeNode* node, int l) {
    if (!node) return;
    by_level[l].push_back(node->val);
    dfs(node->left, l + 1);
    dfs(node->right, l + 1);
  }

public:
  int minimumOperations(TreeNode* root) {
    dfs(root, 0);
    int ans = 0;
    for (int l = 0; l <= 100'000; ++l) {
      int len = by_level[l].size();
      if (len == 0) break;

      unordered_map<int, int> ind;
      for (int i = 0; i < len; i++) ind[by_level[l][i]] = i;
  
      sort(by_level[l].begin(), by_level[l].end());
      vector<bool> visited(len, false);
  
      // Initialize result
      int cur = 0;
      for (int i = 0; i < len; i++) {
        if (visited[i] || ind[by_level[l][i]] == i) continue;

        int j = i, cycle_size = 0;
        while (!visited[j]) {
          visited[j] = true;
          j = ind[by_level[l][j]];
          cycle_size++;
        }
        if (cycle_size > 0) ans += (cycle_size - 1);
      }
    }
    return ans;
  }
};
