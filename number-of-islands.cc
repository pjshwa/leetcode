const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
  bool vis[300][300];
  int n, m;
  vector<vector<char>> grid;

  void dfs(int i, int j) {
    vis[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x >= n || y < 0 || y >= m) continue;
      if (grid[x][y] == '1' && !vis[x][y]) dfs(x, y);
    }
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    n = grid.size(), m = grid[0].size();
    this->grid = grid;
    memset(vis, 0, sizeof(vis));

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (grid[i][j] == '1' && !vis[i][j]) {
        ans++;
        dfs(i, j);
      }
    }

    return ans;
  }
};
