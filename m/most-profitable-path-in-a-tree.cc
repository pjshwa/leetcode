const int INF = 0x3f3f3f3f;

class Solution {
public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    int N = amount.size(), ans = -INF;
    vector<int> adj[N];
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int level[N], parent[N];
    function<void(int, int, int)> dfs1 = [&](int v, int p, int l) {
      level[v] = l; parent[v] = p;
      for (int u : adj[v]) {
        if (u == p) continue;
        dfs1(u, v, l + 1);
      }
    };
    dfs1(0, -1, 0);

    int bobs = level[bob], bobh = bobs / 2;
    while (level[bob] > bobh) {
      amount[bob] = 0;
      bob = parent[bob];
    }
    if (bobs % 2 == 0) amount[bob] /= 2;

    function<void(int, int, int)> dfs2 = [&](int v, int p, int acc) {
      bool leaf = true;
      for (int u : adj[v]) {
        if (u == p) continue;
        dfs2(u, v, acc + amount[u]);
        leaf = false;
      }
      if (leaf) ans = max(ans, acc);
    };
    dfs2(0, -1, amount[0]);
    return ans;
  }
};
