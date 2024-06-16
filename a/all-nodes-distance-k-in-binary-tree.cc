/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

const int MAX = 500;

class Solution {
  vector<int> adj[MAX + 1];

  void dfs(TreeNode* node) {
    if (node->left) {
      adj[node->val].push_back(node->left->val);
      adj[node->left->val].push_back(node->val);
      dfs(node->left);
    }
    if (node->right) {
      adj[node->val].push_back(node->right->val);
      adj[node->right->val].push_back(node->val);
      dfs(node->right);
    }
  }

public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    if (root == nullptr) return vector<int>();

    dfs(root);
    vector<int> cdist(MAX + 1, -1);

    queue<int> Q; int v = target->val;
    Q.push(v); cdist[v] = 0;
    while (!Q.empty()) {
      int v = Q.front(); Q.pop();
      for (int u : adj[v]) {
        if (cdist[u] == -1) {
          cdist[u] = cdist[v] + 1;
          Q.push(u);
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i <= MAX; ++i) {
      if (cdist[i] == k) ans.push_back(i);
    }
    return ans;
  }
};
