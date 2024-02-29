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

const int MAXL = 1e5;

class Solution {
  bool is_si(vector<int>& S) {
    int Z = S.size();
    for (int i = 1; i < Z; ++i) {
      if (S[i] <= S[i - 1]) return false;
    }
    return true;
  }

  bool is_sd(vector<int>& S) {
    int Z = S.size();
    for (int i = 1; i < Z; ++i) {
      if (S[i] >= S[i - 1]) return false;
    }
    return true;
  }

  vector<int> by_level[MAXL];

  void dfs(TreeNode* node, int l) {
    if (node == nullptr) return;
    by_level[l].push_back(node->val);
    dfs(node->left, l + 1);
    dfs(node->right, l + 1);
  }

public:
  bool isEvenOddTree(TreeNode* root) {
    dfs(root, 0);
    for (int l = 0; l < MAXL; ++l) {
      if (l % 2 == 0) {
        if (!is_si(by_level[l])) return false;
        for (int e : by_level[l]) {
          if (e % 2 == 0) return false;
        }
      }
      else {
        if (!is_sd(by_level[l])) return false;
        for (int e : by_level[l]) {
          if (e % 2 == 1) return false;
        }
      }
    }
    return true;
  }
};
