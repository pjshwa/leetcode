class Solution {
public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    int dist[n][n]; memset(dist, 0x3f, sizeof dist);
    for (auto& V : edges) {
      int u = V[0], v = V[1], w = V[2];
      dist[u][v] = min(dist[u][v], w);
      dist[v][u] = min(dist[v][u], w);
    }
    for (int i = 0; i < n; ++i) dist[i][i] = 0;

    for (int k = 0; k < n; ++k) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
      dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int ans = n, cnt = n;
    for (int i = 0; i < n; ++i) {
      int cur = 0;
      for (int j = 0; j < n; ++j) cur += dist[i][j] <= distanceThreshold;
      if (cur <= cnt) cnt = cur, ans = i;
    }
    return ans;
  }
};
