/*
// Definition for a QuadTree node.
class Node {
public:
  bool val;
  bool isLeaf;
  Node* topLeft;
  Node* topRight;
  Node* bottomLeft;
  Node* bottomRight;
  
  Node() {
    val = false;
    isLeaf = false;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }
  
  Node(bool _val, bool _isLeaf) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = NULL;
    topRight = NULL;
    bottomLeft = NULL;
    bottomRight = NULL;
  }
  
  Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
    val = _val;
    isLeaf = _isLeaf;
    topLeft = _topLeft;
    topRight = _topRight;
    bottomLeft = _bottomLeft;
    bottomRight = _bottomRight;
  }
};
*/

class Solution {
  Node* rec(int si, int sj, int d, vector<vector<int>>& grid) {
    int zcnt = 0;
    for (int i = si; i < si + d; i++) for (int j = sj; j < sj + d; j++) {
      zcnt += grid[i][j] == 0;
    }

    if (zcnt == 0) return new Node(true, true);
    if (zcnt == d * d) return new Node(false, true);

    Node* ret = new Node();
    ret->isLeaf = false;
    ret->topLeft = rec(si, sj, d / 2, grid);
    ret->topRight = rec(si, sj + d / 2, d / 2, grid);
    ret->bottomLeft = rec(si + d / 2, sj, d / 2, grid);
    ret->bottomRight = rec(si + d / 2, sj + d / 2, d / 2, grid);
    return ret;
  }

public:
  Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();
    return rec(0, 0, n, grid);
  }
};
