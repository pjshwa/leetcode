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
  unordered_map<TreeNode*, vector<TreeNode*>> graph;
  set<TreeNode*> leaf_set;

  void dfs(TreeNode* node) {
    bool is_leaf = true;
    if (node->left != nullptr) {
      is_leaf = false;
      graph[node].push_back(node->left);
      graph[node->left].push_back(node);
      dfs(node->left);
    }
    if (node->right != nullptr) {
      is_leaf = false;
      graph[node].push_back(node->right);
      graph[node->right].push_back(node);
      dfs(node->right);
    }
    if (is_leaf) {
      leaf_set.insert(node);
    }
  }

public:
  int countPairs(TreeNode* root, int distance) {
    dfs(root);

    int ans = 0;
    for (auto S : leaf_set) {
      queue<TreeNode*> q; q.push(S);
      unordered_map<TreeNode*, int> dist; dist[S] = 0;
      while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node != S && leaf_set.count(node)) ++ans;
        for (auto neighbor : graph[node]) {
          if (!dist.count(neighbor)) {
            dist[neighbor] = dist[node] + 1;
            if (dist[neighbor] <= distance) q.push(neighbor);
          }
        }
      }
    }
    return ans / 2;
  }
};
