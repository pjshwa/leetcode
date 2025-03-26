/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
  Node* lowestCommonAncestor(Node* p, Node * q) {
    int plev = 0, qlev = 0;
    {
      Node* cur = p;
      while (cur) ++plev, cur = cur->parent;
    }
    {
      Node* cur = q;
      while (cur) ++qlev, cur = cur->parent;
    }
    while (plev > qlev) p = p->parent, --plev;
    while (qlev > plev) q = q->parent, --qlev;
    while (p != q) p = p->parent, q = q->parent;
    return p;
  }
};
