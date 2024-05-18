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
  map<TreeNode*, int> C, E;

  void dfsUtil(TreeNode* node) {
    E[node] = 1;
    C[node] = node->val;
    if (node->left) {
      dfsUtil(node->left);
      E[node] += E[node->left];
      C[node] += C[node->left];
    }
    if (node->right) {
      dfsUtil(node->right);
      E[node] += E[node->right];
      C[node] += C[node->right];
    }
  }

public:
  int distributeCoins(TreeNode* root) {
    dfsUtil(root);
    int ans = 0;
    for (auto& [node, _] : E) {
      ans += abs(C[node] - E[node]);
    }
    return ans;
  }
};
