class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    int z = connections.size();
    if (z < n - 1) return -1;

    int parent[n], usz[n];
    iota(parent, parent + n, 0);
    fill(usz, usz + n, 1);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };

    for (auto& e : connections) Union(e[0], e[1]);

    set<int> U;
    for (int i = 0; i < n; i++) U.insert(Find(i));
    return U.size() - 1;
  }
};
