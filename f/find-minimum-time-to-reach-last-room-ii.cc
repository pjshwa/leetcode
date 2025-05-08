const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

class Solution {
public:
  int minTimeToReach(vector<vector<int>>& moveTime) {
    int N = moveTime.size(), M = moveTime[0].size();
    vector<vector<vector<int>>> cdist(N,
      vector<vector<int>>(M, vector<int>(2, INT_MAX)));

    using T = tuple<int, int, int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 0, 0, 0}); cdist[0][0][0] = 0;

    while (!pq.empty()) {
      auto [d, x, y, l] = pq.top(); pq.pop();
      if (cdist[x][y][l] < d) continue;

      for (int k = 0; k < 4; ++k) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

        int nd = max(d, moveTime[nx][ny]) + 1 + l;
        if (nd < cdist[nx][ny][1 - l]) {
          cdist[nx][ny][1 - l] = nd;
          pq.push({nd, nx, ny, 1 - l});
        }
      }
    }

    int ans = INT_MAX;
    for (int l = 0; l < 2; ++l) ans = min(ans, cdist[N - 1][M - 1][l]);
    return ans;
  }
};
