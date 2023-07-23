class Solution {
  vector<TreeNode*> ans, leaves;
  set<TreeNode*> vis;
  TreeNode* root;
  int cnt, tot;

  // copy tree
  TreeNode* copy(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* new_root = new TreeNode(root->val);
    new_root->left = copy(root->left);
    new_root->right = copy(root->right);
    return new_root;
  }

  void dfs(int i) {
    if (cnt == tot) {
      ans.push_back(copy(root));
      return;
    }

    for (int j = i; j < leaves.size(); j++) {
      auto ln = leaves[j];
      if (vis.count(ln)) continue;

      ln->left = new TreeNode(0);
      ln->right = new TreeNode(0);

      leaves.push_back(ln->left);
      leaves.push_back(ln->right);

      cnt++;
      dfs(j + 1);
      cnt--;

      leaves.pop_back();
      leaves.pop_back();

      ln->left = nullptr;
      ln->right = nullptr;
    }
  }

public:
  vector<TreeNode*> allPossibleFBT(int n) {
    if (n % 2 == 0) return {};
    tot = (n - 1) / 2;

    root = new TreeNode(0);
    leaves.push_back(root);
    dfs(0);
    return ans;
  }
};
