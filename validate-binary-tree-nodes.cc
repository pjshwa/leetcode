class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    // edges count should be n - 1
    int edgesCnt = 0;
    for (int i = 0; i < n; ++i) {
      edgesCnt += (leftChild[i] != -1) + (rightChild[i] != -1);
    }
    if (edgesCnt != n - 1) return false;

    // should have only one root
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i) {
      if (leftChild[i] != -1) ++indegree[leftChild[i]];
      if (rightChild[i] != -1) ++indegree[rightChild[i]];
    }

    int root = -1;
    for (int i = 0; i < n; ++i) {
      if (indegree[i] == 0) {
        if (root != -1) return false;
        root = i;
      }
    }
    if (root == -1) return false;

    // should reach all nodes if start from root
    queue<int> q;
    vector<bool> vis(n, false);
    q.push(root); vis[root] = true;

    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (int u : {leftChild[v], rightChild[v]}) {
        if (u == -1) continue;
        vis[u] = true;
        q.push(u);
      }
    }

    return all_of(vis.begin(), vis.end(), [](bool v) { return v; });
  }
};
