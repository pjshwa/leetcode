const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
  int N, M, vis[30][30];

  void dfs(vector<vector<int>>& grid, int i, int j) {
    vis[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] == 0 || vis[x][y]) continue;
      dfs(grid, x, y);
    }
  }

  int getCount(vector<vector<int>>& grid) {
    memset(vis, 0, sizeof(vis));
    int ret = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0 || vis[i][j]) continue;
      dfs(grid, i, j); ++ret;
    }
    return ret;
  }

public:
  int minDays(vector<vector<int>>& grid) {
    N = grid.size(), M = grid[0].size();
    if (getCount(grid) != 1) return 0;

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0) continue;

      grid[i][j] = 0;
      if (getCount(grid) != 1) return 1;
      grid[i][j] = 1;
    }
    return 2;
  }
};
