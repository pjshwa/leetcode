const int MAXN = 500;

class Solution {
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<int> adj[MAXN];
    for (int i = 0; i < n - 1; ++i) adj[i].push_back(i + 1);

    auto cal = [&]() {
      queue<int> q; vector<int> dist(n, -1);
      q.push(0); dist[0] = 0;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
          if (dist[v] == -1) dist[v] = dist[u] + 1, q.push(v);
        }
      }
      return dist[n - 1];
    };

    vector<int> res;
    for (auto& q : queries) {
      adj[q[0]].push_back(q[1]);
      res.push_back(cal());
    }
    return res;
  }
};
