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
  map<TreeNode*, TreeNode*> parent;
  queue<TreeNode*> Q1, Q2;

  void dfs(TreeNode* node) {
    if (node->left) {
      parent[node->left] = node;
      dfs(node->left);
    }
    if (node->right) {
      parent[node->right] = node;
      dfs(node->right);
    }

    if (!node->left && !node->right) {
      Q1.push(node);
    }
  }

public:
  string smallestFromLeaf(TreeNode* root) {
    dfs(root);

    vector<int> ans_v; int f = 1;
    while (f) {
      int minv = 26;
      while (!Q1.empty()) {
        TreeNode* node = Q1.front(); Q1.pop();
        minv = min(minv, node->val);
        Q2.push(node);
      }
      ans_v.push_back(minv);

      while (!Q2.empty()) {
        TreeNode* node = Q2.front(); Q2.pop();
        if (node->val != minv) continue;

        if (parent.count(node)) Q1.push(parent[node]);
        else f = 0;
      }
    }

    string ans;
    for (int e : ans_v) ans.push_back('a' + e);
    return ans;
  }
};
