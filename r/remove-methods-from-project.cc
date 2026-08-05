class Solution {
public:
  vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

    vector<int> adj[n], vis(n);
    for (auto& inv : invocations) {
      adj[inv[0]].push_back(inv[1]);
    }
    queue<int> q;
    q.push(k); vis[k] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : adj[u]) {
        if (vis[v]) continue;
        vis[v] = 1; q.push(v);
      }
    }

    vector<int> indegree(n), ans; int ok = 1;
    for (int u = 0; u < n; ++u) {
      if (vis[u]) continue;
      for (int v : adj[u]) ++indegree[v];
    }
    for (int u = 0; u < n; ++u) {
      if (vis[u] && indegree[u]) { ok = 0; break; }
    }
    for (int u = 0; u < n; ++u) {
      if (!vis[u] || !ok) ans.push_back(u);
    }
    return ans;
  }
};
