class Solution {
public:
  int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
    int n = vals.size();
    vector<int> adj[n];
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int parent[n];
    iota(parent, parent + n, 0);

    function<int(int)> Find = [&](int x) {
      if (x != parent[x]) parent[x] = Find(parent[x]);
      return parent[x];
    };
    function<void(int, int)> Union = [&](int x, int y) {
      x = Find(x); y = Find(y);
      if (x != y) parent[x] = y;
    };

    map<int, vector<int>> by_val;
    for (int i = 0; i < n; i++) by_val[vals[i]].push_back(i);

    int ans = 0;
    for (auto& [val, nodes] : by_val) {
      for (auto& v : nodes) {
        for (auto& u : adj[v]) {
          if (vals[u] <= val) Union(v, u);
        }
      }

      map<int, int> by_group;
      for (auto& v : nodes) by_group[Find(v)]++;

      for (auto& [_, cnt] : by_group) {
        ans += cnt * (cnt - 1) / 2;
      }
    }

    return ans + n;
  }
};
