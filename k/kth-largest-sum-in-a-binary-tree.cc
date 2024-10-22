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
  vector<long long> S;
  void dfs(TreeNode* node, int l) {
    if (node == nullptr) return;
    S[l] += node->val;
    dfs(node->left, l + 1);
    dfs(node->right, l + 1);
  }

public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    S = vector<long long>(MAXN, 0);
    dfs(root, 0);
    sort(S.begin(), S.end(), greater<>());
    return S[k - 1] ? S[k - 1] : -1;
  }
};
