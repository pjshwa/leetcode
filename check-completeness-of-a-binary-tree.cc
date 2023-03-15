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

// Solution 1
class Solution {
  int maxh = 0;
  vector<int> by_hgt[101];

  void dfs(TreeNode* node, int hgt, int idx) {
    if (!node) return;

    maxh = max(maxh, hgt);
    by_hgt[hgt].push_back(idx);

    dfs(node->left, hgt + 1, min(INF, idx * 2));
    dfs(node->right, hgt + 1, min(INF, idx * 2 + 1));
  }

public:
  bool isCompleteTree(TreeNode* root) {
    dfs(root, 0, 1);

    int need = 1;
    for (int h = 0; h < maxh; h++) {
      if (by_hgt[h].size() != need) return false;
      need *= 2;
    }
    if (by_hgt[maxh][0] != need) return false;
    for (int i = 1; i < by_hgt[maxh].size(); i++) {
      if (by_hgt[maxh][i] != by_hgt[maxh][i - 1] + 1) return false;
    }

    return true;
  }
};


// Solution 2
class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    bool f = true;
    while (!q.empty()) {
      auto v = q.front(); q.pop();

      if (v == nullptr) f = false;
      else if (!f) return false;
      else {
        q.push(v->left);
        q.push(v->right);
      }
    }

    return true;
  }
};
