class Solution {
public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    int parent[2 * n], usz[2 * n];
    iota(parent, parent + 2 * n, 0);
    fill(usz, usz + 2 * n, 1);

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

    sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
      return a[0] > b[0];
    });

    int ans = 0;
    for (auto& vv : edges) {
      int t = vv[0], u1 = vv[1] - 1, v1 = vv[2] - 1;
      int u2 = u1 + n, v2 = v1 + n;

      bool g1 = true, g2 = true;
      if (t & 1) g1 = Find(u1) == Find(v1);
      if (t & 2) g2 = Find(u2) == Find(v2);

      if (g1 && g2) ans++;
      else {
        if (!g1) Union(u1, v1);
        if (!g2) Union(u2, v2);
      }
    }

    set<int> U1, U2;
    for (int i = 0; i < n; i++) {
      U1.insert(Find(i));
      U2.insert(Find(i + n));
    }

    if (U1.size() == 1 && U2.size() == 1) return ans;
    else return -1;
  }
};
