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
  map<TreeNode*, vector<TreeNode*>> adj;
  map<TreeNode*, int> dist;
  int start; TreeNode* s;

  void dfs(TreeNode* node) {
    if (node->left) {
      auto ln = node->left;
      adj[node].push_back(ln); adj[ln].push_back(node);
      dfs(ln);
    }
    if (node->right) {
      auto rn = node->right;
      adj[node].push_back(rn); adj[rn].push_back(node);
      dfs(rn);
    }
    if (node->val == start) s = node;
  }

  int bfs() {
    queue<TreeNode*> q;
    q.push(s); dist[s] = 0;
    int ans = 0;
    while (!q.empty()) {
      auto node = q.front(); q.pop();
      for (auto& next : adj[node]) {
        if (dist.count(next)) continue;
        dist[next] = dist[node] + 1;
        ans = max(ans, dist[next]);
        q.push(next);
      }
    }
    return ans;
  }

public:
  int amountOfTime(TreeNode* root, int start) {
    this->start = start;
    dfs(root);
    return bfs();
  }
};
