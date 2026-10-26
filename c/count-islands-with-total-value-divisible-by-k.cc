const int dx[4] = {0, 0, 1, -1},
          dy[4] = {1, -1, 0, 0};

class Solution {
public:
  int countIslands(vector<vector<int>>& grid, int k) {
    int N = grid.size(), M = grid[0].size(), ans = 0;
    vector<vector<int>> vis(N, vector<int>(M, 0));
    auto oob = [&](int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; };

    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0 || vis[i][j]) continue;
      int sum = 0;
      q.push({i, j}); vis[i][j] = 1;
      while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        sum = (sum + grid[x][y]) % k;
        for (int d = 0; d < 4; ++d) {
          int nx = x + dx[d], ny = y + dy[d];
          if (oob(nx, ny) || grid[nx][ny] == 0 || vis[nx][ny]) continue;
          q.push({nx, ny}); vis[nx][ny] = 1;
        }
      }
      if (sum == 0) ++ans;
    }
    return ans;
  }
};
