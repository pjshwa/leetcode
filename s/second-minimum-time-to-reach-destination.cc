const int INF = 0x3f3f3f3f;

class Solution {
public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<int> adj[n + 1];
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v); adj[v].push_back(u);
    }

    int cdist[n + 1][2]; memset(cdist, 0x3f, sizeof(cdist));
    queue<pair<int, int>> Q;
    Q.emplace(1, 0); cdist[1][0] = 0;

    while (!Q.empty()) {
      auto [u, t] = Q.front(); Q.pop();
      int nt = t ^ 1;
      for (int v : adj[u]) {
        if (cdist[v][nt] > cdist[u][t] + 1) {
          cdist[v][nt] = cdist[u][t] + 1;
          Q.emplace(v, nt);
        }
      }
    }

    int opt = min(cdist[n][0], cdist[n][1]), ans;
    if (max(cdist[n][0], cdist[n][1]) == opt + 1) ans = opt + 1;
    else ans = opt + 2;

    int ctime = 0;
    for (int t = 1; t < ans; ++t) {
      ctime += time;

      int rem = ctime % (2 * change);
      if (rem >= change) ctime += 2 * change - rem;
    }
    return ctime + time;
  }
};
