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

const int MAX = 1e4, INF = 0x3f3f3f3f;

class Solution {
  int L[MAX + 1], mlev = 0;

  void dfs(TreeNode* node, int l) {
    int val = node->val;
    L[l] += val; mlev = max(mlev, l);

    if (node->left) dfs(node->left, l + 1);
    if (node->right) dfs(node->right, l + 1);
  }

public:
  int maxLevelSum(TreeNode* root) {
    memset(L, 0, sizeof(L)); dfs(root, 1);

    int mmax = -INF;
    for (int i = 1; i <= mlev; i++) mmax = max(mmax, L[i]);
    for (int i = 1; i <= mlev; i++) if (L[i] == mmax) return i;
    return -1;
  }
};
