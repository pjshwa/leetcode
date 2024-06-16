const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

class Solution {
  int n, m;
  int cnt;
  bool vis[50][50];
  void dfs(int i, int j) {
    vis[i][j] = true;
    cnt++;

    for (int k = 0; k < 4; k++) {
      int nx = i + dx[k], ny = j + dy[k];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
      dfs(nx, ny);
    }
  }
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    n = grid.size(), m = grid[0].size();
    memset(vis, 0, sizeof(vis));

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (grid[i][j] == 0) vis[i][j] = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (vis[i][j]) continue;
      cnt = 0;
      dfs(i, j);
      ans = max(ans, cnt);
    }

    return ans;
  }
};
