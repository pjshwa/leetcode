class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<int> adj[n];
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int asz[n];
    function<int(int, int)> dfs1 = [&](int u, int p) {
      asz[u] = hasApple[u];
      for (int v : adj[u]) {
        if (v == p) continue;
        asz[u] += dfs1(v, u);
      }
      return asz[u];
    };
    dfs1(0, -1);

    int ans = 0;
    function<void(int, int)> dfs2 = [&](int u, int p) {
      for (int v : adj[u]) {
        if (v == p) continue;
        if (asz[v] > 0) {
          ans += 2;
          dfs2(v, u);
        }
      }
    };
    dfs2(0, -1);

    return ans;
  }
};
