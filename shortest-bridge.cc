const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0 ,0};

class Solution {
public:
  int shortestBridge(vector<vector<int>>& grid) {
    int n = grid.size();

    int vis[n][n]; memset(vis, 0, sizeof vis);
    function<void(int, int, int)> dfs = [&](int i, int j, int c) {
      vis[i][j] = c;
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] && !vis[x][y])
          dfs(x, y, c);
      }
    };

    int cc = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (!vis[i][j] && grid[i][j]) dfs(i, j, ++cc);
    }

    queue<pair<int, int>> q;
    int cdist[n][n]; memset(cdist, 0x3f, sizeof cdist);
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (vis[i][j] == 1) q.emplace(i, j), cdist[i][j] = 0;
    }

    int ans = n * n;
    while (!q.empty()) {
      auto [i, j] = q.front(); q.pop();
      if (vis[i][j] == 2) ans = min(ans, cdist[i][j] - 1);

      for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni >= 0 && ni < n && nj >= 0 && nj < n && vis[ni][nj] != 1 && cdist[ni][nj] > cdist[i][j] + 1) {
          cdist[ni][nj] = cdist[i][j] + 1;
          q.emplace(ni, nj);
        }
      }
    }

    return ans;
  }
};
