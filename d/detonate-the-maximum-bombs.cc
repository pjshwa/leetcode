using ll = long long;

class Solution {
public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();
    vector<int> adj[n];

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (i == j) continue;

      ll xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
      ll xj = bombs[j][0], yj = bombs[j][1], rj = bombs[j][2];

      ll dis = (xi - xj) * (xi - xj) + (yi - yj) * (yi - yj);
      if (dis <= ri * ri) adj[i].push_back(j);
    }

    int ans = 0; queue<int> q;
    for (int i = 0; i < n; i++) {
      int cnt = 0, vis[n]; memset(vis, 0, sizeof vis);

      q.push(i); vis[i] = 1;
      while (!q.empty()) {
        int u = q.front(); q.pop(); cnt++;
        for (int v : adj[u]) {
          if (!vis[v]) vis[v] = 1, q.push(v);
        }
      }
      ans = max(ans, cnt);
    }

    return ans;
  }
};
