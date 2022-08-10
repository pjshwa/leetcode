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
  vector<int> nums;

  TreeNode* dfs(int si, int ei) {
    if (si == ei) return nullptr;

    int mid = (si + ei) / 2;
    TreeNode* ret = new TreeNode(nums[mid]);
    ret->left = dfs(si, mid);
    ret->right = dfs(mid + 1, ei);

    return ret;
  }

public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    this->nums = nums;
    return dfs(0, nums.size());
  }
};
