const int MAX = 1e5;
using pii = pair<int, int>;

class Solution {
  int ans, n, k;
  vector<int> adj[MAX];
  set<pii> guesses;
  int run;

  void dfs1(int v, int p) {
    for (int u : adj[v]) {
      if (u == p) continue;

      if (guesses.count({v, u})) run++;
      dfs1(u, v);
    }
  }

  void dfs2(int v, int p) {
    if (run >= k) ans++;
    for (int u : adj[v]) {
      if (u == p) continue;

      bool b1 = guesses.count({v, u}), b2 = guesses.count({u, v});
      if (b1) run--;
      if (b2) run++;
      dfs2(u, v);
      if (b1) run++;
      if (b2) run--;
    }
  }

public:
  int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
    n = edges.size() + 1, this->k = k, ans = 0;
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }
    for (auto &g : guesses) this->guesses.insert({g[0], g[1]});

    run = 0;
    dfs1(0, -1);
    dfs2(0, -1);
    return ans;
  }
};
