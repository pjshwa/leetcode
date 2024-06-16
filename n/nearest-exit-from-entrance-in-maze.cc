const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

class Solution {
  int cdist[100][100];
public:
  int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    int sx = entrance[0], sy = entrance[1];
    int n = maze.size(), m = maze[0].size();
    auto on_border = [&](int x, int y) {
      return x == 0 || x == n - 1 || y == 0 || y == m - 1;
    };

    memset(cdist, 0x3f, sizeof(cdist));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    cdist[sx][sy] = 0;

    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      
      if (on_border(x, y) && !(x == sx && y == sy)) {
        return cdist[x][y];
      }
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (maze[nx][ny] == '+') continue;
        if (cdist[nx][ny] <= cdist[x][y] + 1) continue;
        cdist[nx][ny] = cdist[x][y] + 1;
        q.push({nx, ny});
      }
    }

    return -1;
  }
};
