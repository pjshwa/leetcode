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
  bool isBST(TreeNode* node, int min_val = INT_MIN, int max_val = INT_MAX) {
    if (!node) return true;
    if (node->val <= min_val || node->val >= max_val) return false;
    return isBST(node->left, min_val, node->val) && isBST(node->right, node->val, max_val);
  }

public:
  TreeNode* canMerge(vector<TreeNode*>& trees) {
    map<int, TreeNode*> root_by_val;
    map<TreeNode*, int> idx_by_node;

    int N = trees.size();
    for (int i = 0; i < N; i++) {
      auto tree = trees[i];
      root_by_val[tree->val] = tree;
      idx_by_node[tree] = i;
    }

    int parent[N]; iota(parent, parent + N, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[y] = x;
    };

    bool vis[N]; memset(vis, 0, sizeof(vis));
    for (int i = 0; i < N; i++) {
      auto tree = trees[i];
      auto left = tree->left, right = tree->right;
      if (left && root_by_val.count(left->val)) {
        if (vis[idx_by_node[root_by_val[left->val]]]) return nullptr;
        tree->left = root_by_val[left->val];

        int idx = idx_by_node[tree->left];
        if (Find(i) == Find(idx)) return nullptr;

        vis[idx] = true; Union(i, idx);
      }
      if (right && root_by_val.count(right->val)) {
        if (vis[idx_by_node[root_by_val[right->val]]]) return nullptr;
        tree->right = root_by_val[right->val];

        int idx = idx_by_node[tree->right];
        if (Find(i) == Find(idx)) return nullptr;

        vis[idx] = true; Union(i, idx);
      }
    }

    vector<TreeNode*> roots;
    for (int i = 0; i < N; i++) {
      if (!vis[i]) roots.push_back(trees[i]);
    }
    if (roots.size() != 1) return nullptr;

    auto root = roots[0];
    if (root && isBST(root)) return root;
    else return nullptr;
  }
};
