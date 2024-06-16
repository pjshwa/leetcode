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

const int INF = 1e9 + 7;
using tii = tuple<int, int, int>;

class Solution {
  tii dfs(TreeNode *node) {
    if (!node) return {0, 0, INF};

    auto [l0, l1, l2] = dfs(node->left);
    auto [r0, r1, r2] = dfs(node->right);

    int s0 = l1 + r1;
    int s1 = min(r2 + min(l1, l2), l2 + min(r1, r2));
    int s2 = 1 + min({l0, l1, l2}) + min({r0, r1, r2});

    return {s0, s1, s2};
  }

public:
  int minCameraCover(TreeNode* root) {
    auto [s0, s1, s2] = dfs(root);
    return min(s1, s2);
  }
};
