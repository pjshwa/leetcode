class DSU {
  vector<int> parent, ssz;

public:
  DSU(int n) : parent(n), ssz(n, 1) {
    iota(parent.begin(), parent.end(), 0);
  }

  int Find(int x) {
    if (x != parent[x]) parent[x] = Find(parent[x]);
    return parent[x];
  }

  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;

    parent[y] = x;
    ssz[x] += ssz[y];
  }

  void reset(int x) {
    parent[x] = x;
  }
};

const int MAX = 1e5;
vector<pair<int, int>> meetings_by_time[MAX + 1];

class Solution {
public:
  vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    for (int t = 0; t <= MAX; t++) meetings_by_time[t].clear();
    for (auto m : meetings) {
      int u = m[0], v = m[1], t = m[2];
      meetings_by_time[t].emplace_back(u, v);
    }
    meetings_by_time[0].emplace_back(0, firstPerson);

    DSU dsu(n);
    for (int t = 0; t <= MAX; t++) {
      for (auto [u, v] : meetings_by_time[t]) dsu.Union(u, v);

      int g = dsu.Find(0);
      for (auto [u, v] : meetings_by_time[t]) {
        if (dsu.Find(u) != g) dsu.reset(u);
        if (dsu.Find(v) != g) dsu.reset(v);
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dsu.Find(i) == dsu.Find(0)) ans.push_back(i);
    }
    return ans;
  }
};
