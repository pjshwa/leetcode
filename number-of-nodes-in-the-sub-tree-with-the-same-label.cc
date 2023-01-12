class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> adj[n];
    for (auto& e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int usz[n][26];
    function<void(int, int)> dfs = [&](int u, int p) {
      memset(usz[u], 0, sizeof(usz[u]));
      usz[u][labels[u] - 'a'] = 1;

      for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int i = 0; i < 26; ++i) {
          usz[u][i] += usz[v][i];
        }
      }
    };
    dfs(0, -1);

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = usz[i][labels[i] - 'a'];
    }
    return ans;
  }
};
