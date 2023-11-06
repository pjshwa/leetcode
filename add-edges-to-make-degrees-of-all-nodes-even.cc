class Solution {
public:
  bool isPossible(int n, vector<vector<int>>& edges) {
    int deg[n]; memset(deg, 0, sizeof deg);

    set<int> adj[n];
    for (auto& edge : edges) {
      int u = edge[0] - 1, v = edge[1] - 1;
      ++deg[u]; ++deg[v];
      adj[u].insert(v); adj[v].insert(u);
    }

    vector<int> O;
    for (int i = 0; i < n; ++i) {
      if (deg[i] & 1) O.push_back(i);
    }

    auto contains = [&](int u, int v) {
      return adj[u].count(v);
    };

    if (O.size() == 2) {
      int u = O[0], v = O[1];
      if (!contains(u, v)) return true;
      for (int w = 0; w < n; ++w) {
        if (u == w || v == w) continue;
        if (!contains(u, w) && !contains(v, w)) return true;
      }
    }
    else if (O.size() == 4) {
      int p[4]; iota(p, p + 4, 0);
      do {
        int u = O[p[0]], v = O[p[1]], w = O[p[2]], x = O[p[3]];
        if (!contains(u, v) && !contains(w, x)) return true;

      } while (next_permutation(p, p + 4));
    }
    else if (O.size() == 0) return true;
    
    return false;
  }
};
