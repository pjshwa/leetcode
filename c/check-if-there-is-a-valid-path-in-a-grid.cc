const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const int D[7][2] = {{-1, -1}, {0, 2}, {1, 3}, {1, 2}, {1, 0}, {3, 2}, {3, 0}};

class Solution {
  bool has_d(int t, int d) {
    for (int i = 0; i < 2; ++i) {
      if (D[t][i] == d) return true;
    }
    return false;
  }

public:
  bool hasValidPath(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<bool>> vis(N, vector<bool>(M));
    queue<pair<int, int>> q;
    q.emplace(0, 0); vis[0][0] = true;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (x == N - 1 && y == M - 1) return true;
      for (int d : D[grid[x][y]]) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny]) continue;
        if (has_d(grid[nx][ny], (d + 2) % 4)) {
          vis[nx][ny] = true;
          q.emplace(nx, ny);
        }
      }
    }
    return false;
  }
};
