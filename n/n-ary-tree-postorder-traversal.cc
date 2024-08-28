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
  vector<int> ans;
  void dfs(Node* node) {
    if (node == nullptr) return;
    for (auto child : node->children) dfs(child);
    ans.push_back(node->val);
  }

public:
  vector<int> postorder(Node* root) {
    dfs(root);
    return ans;
  }
};
