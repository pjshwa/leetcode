const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
using pii = pair<int, int>;

class Solution {
public:
  int shortestDistance(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<pii> buildings;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == 1) buildings.push_back({i, j});
    }
    vector<vector<int>> tdist(N, vector<int>(M, 0));
    for (auto& [bi, bj] : buildings) {
      vector<vector<int>> cdist(N, vector<int>(M, -1));
      queue<pii> q;
      q.push({bi, bj}); cdist[bi][bj] = 0;
      while (!q.empty()) {
        auto [i, j] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
          int ni = i + dx[k], nj = j + dy[k];
          if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
          if (grid[ni][nj] != 0 || cdist[ni][nj] != -1) continue;
          cdist[ni][nj] = cdist[i][j] + 1;
          q.push({ni, nj});
        }
      }

      for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (cdist[i][j] == -1) tdist[i][j] = -1;
        else if (tdist[i][j] != -1) tdist[i][j] += cdist[i][j];
      }
    }

    int ans = -1;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] != 0 || tdist[i][j] == -1) continue;
      if (ans == -1 || tdist[i][j] < ans) ans = tdist[i][j];
    }
    return ans;
  }
};
