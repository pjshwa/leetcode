const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int N = moveTime.size(), M = moveTime[0].size();
    vector<vector<int>> cdist(N, vector<int>(M, INT_MAX));

    using T = tuple<int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 0, 0}); cdist[0][0] = 0;

    while (!pq.empty()) {
      auto [d, x, y] = pq.top(); pq.pop();
      if (cdist[x][y] < d) continue;

      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        int nd = max(d, moveTime[nx][ny]) + 1;
        if (nd < cdist[nx][ny]) {
          cdist[nx][ny] = nd;
          pq.push({nd, nx, ny});
        }
      }
    }
    return cdist[N - 1][M - 1];
  }
};
