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
  vector<int> S;

  void dfs1(TreeNode* node, int l) {
    if (node == nullptr) return;
    S[l] += node->val;
    dfs1(node->left, l + 1);
    dfs1(node->right, l + 1);
  }

  void dfs2(TreeNode* node, int psum, int l) {
    if (node == nullptr) return;
    node->val = S[l] - psum;

    int csum = 0;
    if (node->left) csum += node->left->val;
    if (node->right) csum += node->right->val;
    dfs2(node->left, csum, l + 1);
    dfs2(node->right, csum, l + 1);
  }

public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    S.assign(MAXN, 0);
    dfs1(root, 0);
    dfs2(root, root->val, 0);
    return root;
  }
};
