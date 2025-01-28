const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

class Solution {
public:
  int findMaxFish(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size(), ans = 0, cur;
    vector<vector<bool>> vis(N, vector<bool>(M, false));

    auto bfs = [&](int i, int j) {
      queue<pair<int, int>> q;
      q.push({i, j}); vis[i][j] = true;
      cur = 0;
      while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        cur += grid[x][y];
        for (int k = 0; k < 4; ++k) {
          int nx = x + dx[k], ny = y + dy[k];
          if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny] || grid[nx][ny] == 0) continue;
          q.push({nx, ny}); vis[nx][ny] = true;
        }
      }
    };

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 0 || vis[i][j]) continue;
      bfs(i, j); ans = max(ans, cur);
    }
    return ans;
  }
};
