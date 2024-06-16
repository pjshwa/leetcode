class Solution {
public:
  bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
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

    for (auto& e : edges) Union(e[0], e[1]);
    return Find(source) == Find(destination);
  }
};
