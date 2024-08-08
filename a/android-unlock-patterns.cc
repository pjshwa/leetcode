class Solution {
  int l, u, ans = 0;
  bool vis[3][3];

  void dfs(int i, int j, int t) {
    if (t >= l) ++ans;
    if (t == u) return;

    for (int ni = 0; ni < 3; ++ni) for (int nj = 0; nj < 3; ++nj) {
      if (vis[ni][nj]) continue;
      int mi = (i + ni) / 2, mj = (j + nj) / 2;
      if (2 * mi == i + ni && 2 * mj == j + nj && !vis[mi][mj]) continue;
      vis[ni][nj] = true;
      dfs(ni, nj, t + 1);
      vis[ni][nj] = false;
    }
  }

public:
  int numberOfPatterns(int m, int n) {
    l = m, u = n;
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) {
      vis[i][j] = true;
      dfs(i, j, 1);
      vis[i][j] = false;
    }
    return ans;
  }
};
