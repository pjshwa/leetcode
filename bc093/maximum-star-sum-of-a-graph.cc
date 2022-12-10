const int MAX = 1e5;

class Solution {
  vector<int> graph[MAX];
  int deg[MAX];

public:
  int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    memset(deg, 0, sizeof(deg));
    for (auto& edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
      ++deg[u];
      ++deg[v];
    }

    int n = vals.size(), ans = -0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
      priority_queue<int> pq;
      for (int u : graph[i]) {
        pq.push(vals[u]);
      }

      int pk = k, acc = 0;
      while (pk-- && !pq.empty()) {
        if (pq.top() < 0) break;
        acc += pq.top();
        pq.pop();
      }

      ans = max(ans, acc + vals[i]);
    }

    return ans;
  }
};
