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

const int MAXN = 1e5;

class Solution {
  vector<pair<int, int>> adj[MAXN + 1];
  int indegree[MAXN + 1];

  TreeNode* dfs(int v) {
    TreeNode* node = new TreeNode(v);
    for (auto& [u, l] : adj[v]) {
      if (l) node->left = dfs(u);
      else node->right = dfs(u);
    }
    return node;
  }

public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    memset(indegree, 0, sizeof(indegree));
    for (auto& d : descriptions) {
      adj[d[0]].emplace_back(d[1], d[2]);
      ++indegree[d[1]];
    }

    for (int i = 1; i <= MAXN; ++i) {
      if (indegree[i] == 0 && !adj[i].empty()) return dfs(i);
    }
    return nullptr;
  }
};
