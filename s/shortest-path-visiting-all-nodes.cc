const int MAX = 12, INF = 1e9 + 7;

class Solution {
  int cost[MAX][MAX];
  int dist[1 << MAX][MAX];
public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      cost[i][j] = i == j ? 0 : INF;
    }

    for (int u = 0; u < n; u++) {
      for (int v : graph[u]) cost[u][v] = cost[v][u] = 1;
    }

    // Floyd-warshall
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cost[i][j] = min(cost[i][k] + cost[k][j], cost[i][j]);
      }
    }

    for (int i = 0; i < (1 << n); i++) for (int j = 0; j < n; j++) dist[i][j] = INF;

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      dist[1 << i][i] = 0;
      q.push({1 << i, i});
    }

    while (!q.empty()) {
      auto [u, f] = q.front(); q.pop();
      for (int v = 0; v < n; v++) {
        if (u & (1 << v)) continue;
        int d = dist[u][f] + cost[f][v];
        if (dist[u | (1 << v)][v] > d) {
          dist[u | (1 << v)][v] = d;
          q.push({u | (1 << v), v});
        }
      }
    }

    int ans = INF;
    for (int j = 0; j < n; j++) ans = min(ans, dist[(1 << n) - 1][j]);
    return ans;
  }
};
