const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxStability(int n, vector<vector<int>>& edges, int k) {
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
      int au = a[0], av = a[1], as = a[2], am = a[3];
      int bu = b[0], bv = b[1], bs = b[2], bm = b[3];
      if (am != bm) return am < bm;
      return as > bs;
    });

    vector<int> parent(n); int cnt = 0;
    function<int(int)> Find = [&](int x) {
      return parent[x] == x ? x : parent[x] = Find(parent[x]);
    };
    function<void(int, int)> Union = [&](int x, int y) {
      parent[Find(x)] = Find(y); ++cnt;
    };

    int ocnt = 0, omval = INF; iota(parent.begin(), parent.end(), 0);
    while (!edges.empty()) {
      auto& e = edges.back();
      int u = e[0], v = e[1], s = e[2], m = e[3];
      if (!m) break;
      if (Find(u) == Find(v)) return -1;
      Union(u, v); ++ocnt; omval = min(omval, s);
      edges.pop_back();
    }
    vector<int> oparent = parent;

    auto check = [&](int l) {
      parent = oparent;
      cnt = ocnt; int mval = omval, ucnt = 0;
      for (auto& e : edges) {
        int u = e[0], v = e[1], s = e[2];
        if (Find(u) == Find(v) || s * 2 < l) continue;
        if (s < l) s *= 2, ++ucnt;
        Union(u, v);
        mval = min(mval, s);
      }
      return cnt == n - 1 && ucnt <= k && mval >= l;
    };

    int l = 0, r = 2e5 + 1;
    while (l < r) {
      int m = (l + r) / 2;
      if (check(m)) l = m + 1;
      else r = m;
    }
    return l - 1;
  }
};
