class Solution {
public:
  int longestCycle(vector<int>& edges) {
    int n = edges.size();

    int indegree[n];
    memset(indegree, 0, sizeof(indegree));

    for (int i = 0; i < n; ++i) {
      if (edges[i] != -1) indegree[edges[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (!indegree[i]) q.push(i);
    }
    while (!q.empty()) {
      int v = q.front(); q.pop();
      int u = edges[v];
      if (u == -1) continue;
      if (!--indegree[u]) q.push(u);
    }

    int parent[n], usz[n];
    iota(parent, parent + n, 0);
    fill(usz, usz + n, 1);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x == y) return;
      if (usz[x] < usz[y]) swap(x, y);
      parent[y] = x; usz[x] += usz[y];
    };

    int ans = -1;
    for (int i = 0; i < n; ++i) {
      if (indegree[i] && edges[i] != -1) {
        Union(i, edges[i]);
        ans = max(ans, usz[Find(i)]);
      }
    }
    return ans;
  }
};
