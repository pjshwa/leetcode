const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int cdist[n][n];
    memset(cdist, -1, sizeof(cdist));

    queue<pair<int, int>> q;
    if (grid[0][0] == 0) {
      q.push({0, 0});
      cdist[0][0] = 1;
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (int k = 0; k < 8; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if (grid[nx][ny] == 1) continue;
        if (cdist[nx][ny] == -1 || cdist[nx][ny] > cdist[x][y] + 1) {
          cdist[nx][ny] = cdist[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    if (cdist[n - 1][n - 1] == -1) return -1;
    return cdist[n - 1][n - 1];
  }
};
