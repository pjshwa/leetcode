#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

const int MAXN = 100001;

class Solution {
public:
  TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
    map<int, TreeNode*> nodes; int indegree[MAXN + 1] = {0};
    for (auto& d : descriptions) {
      int parent = d[0], child = d[1], isLeft = d[2];
      if (!nodes.count(parent)) nodes[parent] = new TreeNode(parent);
      if (!nodes.count(child)) nodes[child] = new TreeNode(child);
      if (isLeft) nodes[parent]->left = nodes[child];
      else nodes[parent]->right = nodes[child];
      ++indegree[child];
    }
    for (auto& [val, node] : nodes) {
      if (!indegree[val]) return node;
    }
    return nullptr;
  }
};
