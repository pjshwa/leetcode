/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  map<TreeNode*, TreeNode*> pleft, pright;

  void dfs(TreeNode* node) {
    if (!node) return;
    if (node->left) {
      pright[node->left] = node;
      dfs(node->left);
    }
    if (node->right) {
      pleft[node->right] = node;
      dfs(node->right);
    }
  }

public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    dfs(root);
    if (p->right) {
      auto l = p->right;
      while (l->left) l = l->left;
      return l;
    } else {
      auto l = p;
      while (!pright.count(l)) {
        if (l == root) return nullptr;
        l = pleft[l];
      }
      return pright[l];
    }
  }
};
