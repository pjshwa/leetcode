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
  int vis[MAXN + 1], from[MAXN + 1], dir[MAXN + 1];
  vector<pair<int, int>> adj[MAXN + 1];

  void dfs(TreeNode* node) {
    int val = node->val;
    if (node->left) {
      int lval = node->left->val;
      adj[val].emplace_back(lval, 0); adj[lval].emplace_back(val, -1);
      dfs(node->left);
    }
    if (node->right) {
      int rval = node->right->val;
      adj[val].emplace_back(rval, 1); adj[rval].emplace_back(val, -1);
      dfs(node->right);
    }
  }

public:
  string getDirections(TreeNode* root, int startValue, int destValue) {
    dfs(root);

    queue<int> Q;
    memset(vis, 0, sizeof(vis));
    Q.push(startValue); vis[startValue] = 1;

    while (!Q.empty()) {
      int u = Q.front(); Q.pop();
      if (u == destValue) break;

      for (auto [v, d] : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1; from[v] = u; dir[v] = d;
        Q.push(v);
      }
    }

    int u = destValue; string ans = "";
    while (u != startValue) {
      int d = dir[u];
      if (d == -1) ans += "U";
      else if (d == 0) ans += "L";
      else ans += "R";
      u = from[u];
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
