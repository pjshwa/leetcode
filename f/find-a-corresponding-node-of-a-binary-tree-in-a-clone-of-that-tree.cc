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
  vector<int> path, cur;
  TreeNode* ans;

  void dfs1(TreeNode* node, TreeNode* target) {
    if (node == target) path = cur;
    if (node->left) {
      cur.push_back(0);
      dfs1(node->left, target);
      cur.pop_back();
    }
    if (node->right) {
      cur.push_back(1);
      dfs1(node->right, target);
      cur.pop_back();
    }
  }

  void dfs2(TreeNode* node, int idx) {
    if (idx == path.size()) return ans = node, void();
    if (path[idx]) dfs2(node->right, idx + 1);
    else dfs2(node->left, idx + 1);
  }

public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
    dfs1(original, target);
    dfs2(cloned, 0);
    return ans;
  }
};
