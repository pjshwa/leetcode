const int MAX = 2e5, BIAS = 1e5;

class Solution {
public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    vector<int> adj[MAX + 1];
    int deg[MAX + 1]; memset(deg, 0, sizeof deg);
    for (auto& e : adjacentPairs) {
      int u = e[0] + BIAS, v = e[1] + BIAS;
      adj[u].push_back(v); adj[v].push_back(u);
      ++deg[u]; ++deg[v];      
    }

    queue<int> q;
    vector<bool> vis(MAX + 1, false);
    for (int i = 0; i <= MAX; ++i) {
      if (deg[i] != 1) continue;
      q.push(i); vis[i] = true;
      break;
    }

    vector<int> ans;
    while (!q.empty()) {
      int v = q.front(); q.pop();
      ans.push_back(v - BIAS);

      for (int u : adj[v]) {
        if (vis[u]) continue;
        q.push(u); vis[u] = true;
      }
    }

    return ans;
  }
};
