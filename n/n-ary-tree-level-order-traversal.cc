/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  vector<int> by_level[1001];

  void dfs(Node* v, int l) {
    by_level[l].push_back(v->val);
    for (auto u : v->children) {
      if (u) dfs(u, l + 1);
    }
  }

public:
  vector<vector<int>> levelOrder(Node* root) {
    if (root) dfs(root, 0);

    vector<vector<int>> ans;
    for (int l = 0; l <= 1000; l++) {
      if (by_level[l].empty()) break;
      ans.push_back(by_level[l]);
    }

    return ans;
  }
};
