const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    int N = land.size(), M = land[0].size();
    vector<vector<int>> vis(N, vector<int>(M, 0)), res;

    queue<pair<int, int>> q;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (land[i][j] == 0 || vis[i][j]) continue;

      int si = i, sj = j, ei = i, ej = j;
      q.push({i, j}); vis[i][j] = 1;
      while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        ei = max(ei, x); ej = max(ej, y);
        for (int d = 0; d < 4; ++d) {
          int nx = x + dx[d], ny = y + dy[d];
          if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
          if (land[nx][ny] == 0 || vis[nx][ny]) continue;
          q.push({nx, ny}); vis[nx][ny] = 1;
        }
      }
      res.push_back({si, sj, ei, ej});
    }

    return res;
  }
};
