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
  vector<int> cur;
  void dfs(TreeNode* node) {
    if (node->left) {
      if (node->right) {
        dfs(node->left);
        dfs(node->right);
      }
      else dfs(node->left);
    }
    else if (node->right) dfs(node->right);
    else cur.push_back(node->val);
  }

public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    cur.clear();
    dfs(root1);
    vector<int> v1 = cur;
    cur.clear();
    dfs(root2);
    vector<int> v2 = cur;

    return v1 == v2;
  }
};
