/*
// Definition for a Node.
class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
*/

class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node) return nullptr;

    bool vis[101]{}; Node *nodes[101]{};
    for (int i = 1; i <= 100; i++) nodes[i] = new Node(i);

    queue<pair<Node*, Node*>> q;
    q.push({node, nodes[node->val]});
    vis[node->val] = true;

    while (!q.empty()) {
      auto [ou, nu] = q.front(); q.pop();
      for (auto v : ou->neighbors) {
        int nval = v->val;
        nodes[ou->val]->neighbors.push_back(nodes[nval]);

        if (!vis[nval]) {
          q.push({v, nodes[nval]});
          vis[nval] = true;
        }
      }
    }

    return nodes[node->val];
  }
};
