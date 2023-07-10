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

const int INF = 0x3f3f3f3f;

class Solution {
  int ans = INF;

  void dfs(TreeNode* node, int depth) {
    if (node == nullptr) return;
    if (node->left == nullptr && node->right == nullptr) {
      ans = min(ans, depth);
      return;
    }
    dfs(node->left, depth + 1);
    dfs(node->right, depth + 1);
  }

public:
  int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    dfs(root, 1);
    return ans;
  }
};
