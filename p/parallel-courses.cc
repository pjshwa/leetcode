class Solution {
public:
  int minimumSemesters(int n, vector<vector<int>>& relations) {
    vector<int> adj[n];
    int indegree[n]; memset(indegree, 0, sizeof indegree);

    for (auto& rel : relations) {
      int u = rel[0] - 1, v = rel[1] - 1;
      adj[u].push_back(v); ++indegree[v];
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) if (!indegree[i]) q.push(i);

    int ans, used = 0;
    for (ans = 0; q.size(); ++ans) {
      queue<int> nq;
      while (!q.empty()) {
        int v = q.front(); q.pop();
        ++used;

        for (int u : adj[v]) {
          if (!--indegree[u]) nq.push(u);
        }
      }
      q = nq;
    }

    return used == n ? ans : -1;
  }
};
