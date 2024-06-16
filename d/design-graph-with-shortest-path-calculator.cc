using pii = pair<int, int>;

class Graph {
  vector<vector<pii>> adj;

public:
  Graph(int n, vector<vector<int>>& edges) {
    adj.resize(n);
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      adj[u].push_back({v, w});
    }
  }
  
  void addEdge(vector<int> edge) {
    int u = edge[0], v = edge[1], w = edge[2];
    adj[u].push_back({v, w});
  }
  
  int shortestPath(int node1, int node2) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> cdist(adj.size(), INT_MAX);
    pq.push({0, node1}); cdist[node1] = 0;

    while (!pq.empty()) {
      auto [dist, node] = pq.top(); pq.pop();
      if (dist > cdist[node]) continue;

      for (auto [v, w] : adj[node]) {
        if (dist + w < cdist[v]) {
          cdist[v] = dist + w;
          pq.push({cdist[v], v});
        }
      }
    }

    return cdist[node2] == INT_MAX ? -1 : cdist[node2];
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
 