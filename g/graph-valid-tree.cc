class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    int parent[n];
    iota(parent, parent + n, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    if (edges.size() != n - 1) return false;
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      if (Find(u) == Find(v)) return false;
      Union(u, v);
    }
    return true;
  }
};
