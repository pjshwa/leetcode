const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  int getMaximumGold(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> vis(N, vector<int>(M, 0));

    auto oob = [&](int x, int y) {
      return x < 0 || x >= N || y < 0 || y >= M;
    };

    function<int(int, int)> dfs = [&](int x, int y) {
      if (oob(x, y) || grid[x][y] == 0 || vis[x][y]) return 0;
      vis[x][y] = 1; int ret = 0;
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        ret = max(ret, dfs(nx, ny));
      }
      vis[x][y] = 0;
      return ret + grid[x][y];
    };

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0) continue;
      ans = max(ans, dfs(i, j));
    }
    return ans;
  }
};
