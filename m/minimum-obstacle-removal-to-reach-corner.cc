const int INF = 0x3f3f3f3f;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    deque<pair<int, int>> dq;
    vector<vector<int>> cdist(N, vector<int>(M, INF));
    dq.emplace_back(0, 0); cdist[0][0] = 0;

    while (!dq.empty()) {
      auto [x, y] = dq.front(); dq.pop_front();
      int d = cdist[x][y];
      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        int nd = cdist[x][y] + grid[nx][ny];
        if (nd < cdist[nx][ny]) {
          cdist[nx][ny] = nd;
          if (d == nd) dq.emplace_front(nx, ny);
          else dq.emplace_back(nx, ny);
        }
      }
    }
    return cdist[N - 1][M - 1];
  }
};
