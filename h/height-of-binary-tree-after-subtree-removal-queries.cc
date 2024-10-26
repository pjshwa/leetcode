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
  TreeNode* by_val[MAXN + 1];
  int parent[MAXN + 1], levs[MAXN + 1], L[MAXN + 1], R[MAXN + 1], vis[MAXN + 1];
  int maxl = 0, maxp = -1;

  void dfs1(TreeNode* node, int p, int l) {
    if (node == nullptr) return;

    int val = node->val;
    by_val[val] = node; parent[val] = p;
    L[val] = l; ++levs[l]; maxl = max(maxl, l);
    dfs1(node->left, val, l + 1);
    dfs1(node->right, val, l + 1);
  }

  void dfs2(TreeNode* node, int l) {
    int val = node->val;
    R[val] = l == maxl;
    if (node->left) {
      dfs2(node->left, l + 1);
      R[val] += R[node->left->val];
    }
    if (node->right) {
      dfs2(node->right, l + 1);
      R[val] += R[node->right->val];
    }
    if (R[val] == levs[maxl] && maxp == -1) maxp = val;
  }

  void dfs3(int nodep, int l) {
    TreeNode* node = by_val[nodep];
    int val = node->val;
    vis[val] = 1; --levs[l];

    if (node->left && !vis[node->left->val]) {
      dfs3(node->left->val, l + 1);
    }
    if (node->right && !vis[node->right->val]) {
      dfs3(node->right->val, l + 1);
    }
  }

public:
  vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    memset(levs, 0, sizeof levs);
    dfs1(root, 0, 0);

    // find the node with the maximum level, of which when removed,
    // the height of the tree will decrease
    // only this node and its ancestors can affect the height of the tree
    dfs2(root, 0);

    fill(R, R + MAXN + 1, maxl);
    while (maxp != root->val) {
      dfs3(maxp, L[maxp]);
      while (levs[maxl] == 0) --maxl;
      R[maxp] = maxl;
      maxp = parent[maxp];
    }

    vector<int> res;
    for (int q : queries) res.push_back(R[q]);
    return res;
  }
};
