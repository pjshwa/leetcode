#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 1e5, MOD = 1e9 + 7;


ll lpow(ll x, ll y, ll m) {
  ll r = 1;
  x %= m;
  while (y) {
    if (y & 1) r = (r * x) % m;
    x = (x * x) % m;
    y >>= 1;
  }
  return r;
}

class Solution {
  vector<vector<int>> adj, parent;
  vector<int> level;
  vector<bool> vis;

  void init(int n) {
    adj.resize(n + 1);
    parent.assign(n + 1, vector<int>(20));
    level.resize(n + 1);
    vis.assign(n + 1, false);
  }

  void dfs(int node, int lv) {
    vis[node] = true;
    level[node] = lv;

    for (int el : adj[node]) {
      if (!vis[el]) {
        parent[el][0] = node;
        dfs(el, lv + 1);
      }
    }
  }

  int lca(int x, int y) {
    if (level[x] < level[y]) swap(x, y);
    int diff = level[x] - level[y];

    for (int i = 0; diff; i++) {
      if (diff % 2) x = parent[x][i];
      diff /= 2;
    }

    // level[x] = level[y] from now on.
    if (x != y) {
      for (int i = 19; i >= 0; i--) {
        if (!parent[x][i] || parent[x][i] == parent[y][i]) continue;

        x = parent[x][i];
        y = parent[y][i];
      }

      x = parent[x][0];
    }
    
    return x;
  }

  int dist(int x, int y) {
    return level[x] + level[y] - 2 * level[lca(x, y)];
  }

public:
  vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int N = edges.size() + 1;
    init(N);

    for (auto& e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, 0);
    for (int j = 0; j < 20; j++)
      for (int i = 2; i <= N; i++)
        if (parent[i][j]) parent[i][j + 1] = parent[parent[i][j]][j];

    vector<int> ans;
    for (auto& q : queries) {
      int u = q[0], v = q[1];
      int a = dist(u, v);
      ans.push_back(a == 0 ? 0 : lpow(2, a - 1, MOD));
    }
    return ans;
  }
};
