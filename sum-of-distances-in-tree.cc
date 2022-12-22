const int MAX = 3e4;

class Solution {
  vector<int> graph[MAX];
  vector<int> ans;
  int ssz[MAX], usz[MAX];

  void dfs1(int v, int p) {
    ssz[v] = 1;
    for (int u : graph[v]) {
      if (u == p) continue;
      dfs1(u, v);
      ssz[v] += ssz[u];
    }
  }

  void dfs2(int v, int p) {
    usz[v] = 0;
    for (int u : graph[v]) {
      if (u == p) continue;
      dfs2(u, v);
      usz[v] += usz[u] + ssz[u];
    }
  }

  void dfs3(int v, int p, int o) {
    ans[v] = o;
    for (int u : graph[v]) {
      if (u == p) continue;
      dfs3(u, v, o - ssz[u] + (ssz[0] - ssz[u]));
    }
  }

public:
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    ans.resize(n);
    for (auto& ev : edges) {
      int u = ev[0], v = ev[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);
    dfs3(0, -1, usz[0]);

    return ans;
  }
};