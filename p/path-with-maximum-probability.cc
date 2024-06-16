class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<pair<int, double>> graph[n];
    for (int i = 0; i < edges.size(); i++) {
      graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
      graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
    }

    double cdist[n]; memset(cdist, 0, sizeof(cdist));
    priority_queue<pair<double, int>> pq;
    pq.push({1, start}); cdist[start] = 1;

    while (!pq.empty()) {
      auto [c, u] = pq.top(); pq.pop();
      for (auto [v, w] : graph[u]) {
        if (cdist[v] < c * w) {
          cdist[v] = c * w;
          pq.push({cdist[v], v});
        }
      }
    }
    return cdist[end];
  }
};
