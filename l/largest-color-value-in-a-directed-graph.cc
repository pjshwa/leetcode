class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<int> adj[n], indegree(n, 0);
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      indegree[e[1]]++;
    }

    auto is_cyclic = [&](){
      auto D = indegree;
      queue<int> q;
      for (int i = 0; i < n; i++) if (D[i] == 0) q.push(i);

      for (int i = 0; i < n; i++) {
        if (q.empty()) return true;
        int u = q.front(); q.pop();
        for (auto& v : adj[u]) if (--D[v] == 0) q.push(v);
      }
      return false;
    };
    if (is_cyclic()) return -1;

    vector<vector<int>> d(n, vector<int>(26, 0));
    vector<int> vis(n, 0);
    function<void(int)> dfs = [&](int v) {
      int c = colors[v] - 'a';
      vis[v] = 1;
      for (int u : adj[v]) {
        if (!vis[u]) dfs(u);
        for (int i = 0; i < 26; i++) {
          d[v][i] = max(d[v][i], d[u][i]);
        }
      }
      d[v][c]++;
    };
    for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < 26; j++) {
      ans = max(ans, d[i][j]);
    }
    return ans;
  }
};
