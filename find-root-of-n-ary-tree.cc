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
public:
  Node* findRoot(vector<Node*> tree) {
    set<Node*> S;
    for (int i = 0; i < tree.size(); i++) {
      for (int j = 0; j < tree[i]->children.size(); j++) {
        S.insert(tree[i]->children[j]);
      }
    }

    Node* ans = nullptr;
    for (int i = 0; i < tree.size(); i++) {
      if (S.find(tree[i]) == S.end()) ans = tree[i];
    }
    return ans;
  }
};
