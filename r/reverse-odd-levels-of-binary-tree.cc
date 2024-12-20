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

const int MAXN = 1 << 14;

class Solution {
  vector<int> by_l[MAXN + 1];

  void dfs1(TreeNode* node, int l) {
    if (node == nullptr) return;
    by_l[l].push_back(node->val);
    dfs1(node->left, l + 1);
    dfs1(node->right, l + 1);
  }

  void dfs2(TreeNode* node, int l) {
    if (node == nullptr) return;
    if (l & 1) {
      node->val = by_l[l].back();
      by_l[l].pop_back();
    }
    dfs2(node->left, l + 1);
    dfs2(node->right, l + 1);
  }

public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    dfs1(root, 0);
    dfs2(root, 0);
    return root;
  }
};
