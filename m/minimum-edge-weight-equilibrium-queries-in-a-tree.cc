const int MAXN = 1e4, MAXW = 26;

int par[MAXN][15], level[MAXN];
int wsum[MAXW + 1][MAXN][15]; // how many wi's in path?

class Solution {
  int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);

    int dif = level[u] - level[v];
    for (int i = 0; dif; ++i) {
      if (dif & 1) u = par[u][i];
      dif /= 2;
    }
    if (u == v) return u;

    for (int i = 14; i >= 0; --i) {
      if (u == -1 || v == -1) break;
      if (par[u][i] == -1 || par[u][i] == par[v][i]) continue;
      u = par[u][i], v = par[v][i];
    }
    return par[u][0];
  }

  int sum_by_w(int u, int v, int w) {
    int common_p = lca(u, v), ret = 0;
    for (int x : {u, v}) {
      int dif = level[x] - level[common_p];
      for (int i = 0; dif; ++i) {
        if (dif & 1) {
          ret += wsum[w][x][i];
          x = par[x][i];
        }
        dif /= 2;
      }
    }
    return ret;
  }

public:
  vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    for (int i = 0; i < n; ++i) for (int p = 0; p < 15; ++p) {
      par[i][p] = -1;
      for (int w = 0; w <= 26; ++w) wsum[w][i][p] = 0;
    }

    vector<pair<int, int>> adj[n];
    for (auto& e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].emplace_back(v, w);
      adj[v].emplace_back(u, w);
    }

    function<void(int, int)> dfs = [&](int v, int p) {
      for (auto& [u, w] : adj[v]) {
        if (u == p) continue;
        par[u][0] = v;
        level[u] = level[v] + 1;
        wsum[w][u][0] = wsum[0][u][0] = 1;
        dfs(u, v);
      }
    };
    level[0] = 0;
    dfs(0, -1);

    for (int p = 1; p < 15; ++p) for (int i = 0; i < n; ++i) {
      int lp = par[i][p - 1];
      if (lp == -1) continue;

      par[i][p] = par[lp][p - 1];
      for (int w = 0; w <= 26; ++w) {
        wsum[w][i][p] = wsum[w][lp][p - 1] + wsum[w][i][p - 1];
      }
    }

    vector<int> ans;
    for (auto& query : queries) {
      int u = query[0], v = query[1];
      int total = sum_by_w(u, v, 0);

      int result = total;
      for (int w = 1; w <= 26; ++w) result = min(result, total - sum_by_w(u, v, w));
      ans.push_back(result);
    }
    return ans;
  }
};
