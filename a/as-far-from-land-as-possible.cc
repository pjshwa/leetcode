const int INF = 0x3f3f3f3f;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class Solution {
public:
  int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size();

    int cdist[n][n];
    for (int i = 0; i < n; i++) fill(cdist[i], cdist[i] + n, INF);

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) {
        cdist[i][j] = 0;
        q.push({i, j});
      }
    }

    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (cdist[nx][ny] > cdist[x][y] + 1) {
          cdist[nx][ny] = cdist[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    int ans = -1;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
      if (grid[i][j] == 1) continue;
      ans = max(ans, cdist[i][j]);
    }
    return ans == INF ? -1 : ans;
  }
};
