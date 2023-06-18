using pii = pair<int, int>;

const int MOD = 1e9 + 7;
const int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};

class Solution {
public:
  int countPaths(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> d(N, vector<int>(M));

    priority_queue<pair<int, pii>> pq;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
      pq.push({-grid[i][j], {i, j}});
    }

    int ans = 0;
    while (!pq.empty()) {
      auto [v, p] = pq.top(); pq.pop(); auto [x, y] = p;

      d[x][y] = 1;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (grid[nx][ny] < grid[x][y]) d[x][y] = (d[x][y] + d[nx][ny]) % MOD;
      }
      ans = (ans + d[x][y]) % MOD;
    }
    return ans;
  }
};
