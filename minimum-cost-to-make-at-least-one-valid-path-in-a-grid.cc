const int dx[] = {0, 0, 0, 1, -1}, dy[] = {0, 1, -1, 0, 0};

class Solution {
public:
  int minCost(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    int cdist[N][M][5]; memset(cdist, 0x3f, sizeof(cdist));
    deque<tuple<int, int, int>> dq;
    for (int k = 1; k <= 4; ++k) {
      dq.emplace_back(0, 0, k);
      cdist[0][0][k] = 0;
    }

    while (!dq.empty()) {
      auto [x, y, d] = dq.front(); dq.pop_front();
      for (int k = 1; k <= 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        int cost = k != grid[x][y];
        if (cdist[nx][ny][k] > cdist[x][y][d] + cost) {
          cdist[nx][ny][k] = cdist[x][y][d] + cost;
          if (cost == 0) dq.emplace_front(nx, ny, k);
          else dq.emplace_back(nx, ny, k);
        }
      }
    }

    int ans = 0x3f3f3f3f;
    for (int k = 1; k <= 4; ++k) ans = min(ans, cdist[N-1][M-1][k]);
    return ans;
  }
};
