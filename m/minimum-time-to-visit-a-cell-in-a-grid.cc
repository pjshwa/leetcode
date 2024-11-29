const int INF = 0x3f3f3f3f;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Solution {
public:
  int minimumTime(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    if (grid[1][0] > 1 && grid[0][1] > 1) return -1;

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if ((i + j) % 2 != grid[i][j] % 2) grid[i][j] += 1;
    }

    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<vector<int>> cdist(N, vector<int>(M, INF));
    pq.emplace(0, 0, 0); cdist[0][0] = 0;

    while (!pq.empty()) {
      auto [d, i, j] = pq.top(); pq.pop();
      if (cdist[i][j] < d) continue;

      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
        int nd = max(d + 1, grid[ni][nj]);
        if (cdist[ni][nj] > nd) {
          cdist[ni][nj] = nd;
          pq.emplace(nd, ni, nj);
        }
      }
    }

    return cdist.back().back();
  }
};
