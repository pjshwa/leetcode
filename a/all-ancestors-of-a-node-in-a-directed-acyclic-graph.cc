class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<int> adj[n];
    for (auto& e : edges) adj[e[1]].push_back(e[0]);

    vector<vector<int>> ans;
    queue<int> q; vector<int> vis(n);
    for (int i = 0; i < n; ++i) {
      fill(vis.begin(), vis.end(), 0);
      q.push(i); vis[i] = 1;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
          if (!vis[v]) vis[v] = 1, q.push(v);
        }
      }

      vector<int> cur;
      for (int j = 0; j < n; ++j) {
        if (i != j && vis[j]) cur.push_back(j);
      }
      ans.push_back(cur);
    }
    return ans;
  }
};
