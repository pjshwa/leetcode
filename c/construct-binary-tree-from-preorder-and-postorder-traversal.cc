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
  TreeNode* constructHelper(vector<int>& preorder, vector<int>& postorder, int si, int ei, int sj, int ej) {
    if (si > ei) return nullptr;

    TreeNode* root = new TreeNode(preorder[si]);
    int fj = -1;
    for (int j = sj; j <= ej && si < ei; ++j) {
      if (postorder[j] == preorder[si + 1]) fj = j;
    }
    if (fj != -1) {
      root->left = constructHelper(preorder, postorder, si + 1, si + 1 + fj - sj, sj, fj);
      root->right = constructHelper(preorder, postorder, si + 1 + fj - sj + 1, ei, fj + 1, ej - 1);
    }
    return root;
  }

public:
  TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    return constructHelper(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
  }
};
