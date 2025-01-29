class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    int parent[n + 1];

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    iota(parent, parent + n + 1, 0);
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      if (Find(u) == Find(v)) return e;
      Union(u, v);
    }
    return {};
  }
};
