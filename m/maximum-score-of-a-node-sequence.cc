class Solution {
public:
  int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
    int n = scores.size();

    vector<int> adj[n];
    priority_queue<pair<int, int>> adj_scores[n];
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v); adj[v].push_back(u);
      adj_scores[u].emplace(scores[v], v);
      adj_scores[v].emplace(scores[u], u);
    }

    int ans = -1;
    for (auto e : edges) {
      int u = e[0], v = e[1];
      
      for (int it = 0; it < 2; ++it) {
        int w = -1, x = -1;

        queue<pair<int, int>> uq, vq;
        while (!adj_scores[u].empty() && adj_scores[u].top().second == v) {
          uq.push(adj_scores[u].top()); adj_scores[u].pop();
        }
        if (!adj_scores[u].empty()) w = adj_scores[u].top().second;

        while (!adj_scores[v].empty() && (adj_scores[v].top().second == u || adj_scores[v].top().second == w)) {
          vq.push(adj_scores[v].top()); adj_scores[v].pop();
        }
        if (!adj_scores[v].empty()) x = adj_scores[v].top().second;

        if (w != -1 && x != -1) {
          ans = max(ans, scores[u] + scores[v] + scores[w] + scores[x]);
        }

        while (!uq.empty()) {
          adj_scores[u].push(uq.front()); uq.pop();
        }
        while (!vq.empty()) {
          adj_scores[v].push(vq.front()); vq.pop();
        }

        swap(u, v);
      }
      
    }

    return ans;
  }
};
