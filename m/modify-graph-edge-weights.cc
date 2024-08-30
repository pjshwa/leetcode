const int INF = 0x3f3f3f3f;

class Solution {
public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    int cdist[n][n], mdist[n][n], from[n][n], from_w[n][n];
    memset(cdist, 0x3f, sizeof cdist);
    memset(mdist, -1, sizeof mdist);
    memset(from, -1, sizeof from);
    memset(from_w, -1, sizeof from_w);

    vector<pair<int, int>> adj[n];
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      mdist[u][v] = mdist[v][u] = w;
    }

    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    cdist[source][0] = 0; pq.push({0, 0, source});

    while (!pq.empty()) {
      auto [d, c, u] = pq.top(); pq.pop();
      for (auto& [v, w] : adj[u]) {
        int nc, nd;
        if (w == -1) nc = c + 1, nd = d;
        else nc = c, nd = d + w;

        if (nc < n && nd < cdist[v][nc]) {
          cdist[v][nc] = nd;
          from[v][nc] = u; from_w[v][nc] = w;
          pq.push({nd, nc, v});
        }
      }
    }

    int c;
    for (c = 0; c < n; ++c) {
      if (cdist[destination][c] + c <= target) break;
    }
    if (c == n) return {};

    int u = destination, diff = target - cdist[destination][c];
    vector<tuple<int, int, int>> traj;
    while (1) {
      int v = from[u][c]; int nc = c;
      if (v == -1) break;
      if (from_w[u][c] == -1) --nc;
      traj.push_back({v, u, from_w[u][c]});
      u = v; c = nc;
    }

    int mcnt = 0;
    for (auto& t : traj) {
      auto [u, v, w] = t;
      mcnt += w == -1;
    }
    for (auto& t : traj) {
      auto [u, v, w] = t;
      if (w != -1) continue;
      if (--mcnt == 0) w = diff, diff = 0;
      else w = 1, --diff;
      mdist[u][v] = mdist[v][u] = w;
    }
    if (diff > 0) return {};

    vector<vector<int>> res;
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = mdist[u][v] == -1 ? target + 1 : mdist[u][v];
      res.push_back({u, v, w});
    }
    return res;
  }
};
