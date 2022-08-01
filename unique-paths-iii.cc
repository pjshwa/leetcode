const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

class Solution {
  bool vis[20][20];
  vector<vector<int>> grid;
  int cc = 0, total = 0, ans = 0, si, sj, ei, ej, n, m;

  void dfs(int i, int j) {
    if (i == ei && j == ej) {
      if (cc == total - 1) ans++;
      return;
    }

    vis[i][j] = true;
    cc++;
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k], nj = j + dy[k];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m || vis[ni][nj] || grid[ni][nj] == -1)
        continue;
      dfs(ni, nj);
    }
    vis[i][j] = false;
    cc--;
  }

public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    this->grid = grid;
    n = grid.size(), m = grid[0].size();
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (grid[i][j] != -1) total++;
      if (grid[i][j] == 1) si = i, sj = j;
      if (grid[i][j] == 2) ei = i, ej = j;
    }

    memset(vis, 0, sizeof(vis));
    dfs(si, sj);

    return ans;
  }
};
