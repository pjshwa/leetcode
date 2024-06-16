const int MAX = 3e4;

class Solution {
  vector<int> graph[MAX], ans;
  int usz[MAX];

  int dfs1(int v, int p) {
    usz[v] = 1; int ret = 0;
    for (int u : graph[v]) {
      if (u == p) continue;
      ret += dfs1(u, v);
      ret += usz[u];
      usz[v] += usz[u];
    }
    return ret;
  }

  void dfs2(int v, int p, int acc) {
    ans[v] = acc;
    for (int u : graph[v]) {
      if (u == p) continue;
      dfs2(u, v, acc + usz[0] - 2 * usz[u]);
    }
  }

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    ans.resize(n);
    for (auto& e : edges) {
      int u = e[0], v = e[1];
      graph[u].push_back(v); graph[v].push_back(u);
    }
    
    int acc = dfs1(0, -1);
    dfs2(0, -1, acc);
    return ans;
  }
};
