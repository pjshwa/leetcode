const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  int getFood(vector<vector<char>>& grid) {
    int N = grid.size(), M = grid[0].size();

    queue<pair<int, int>> q;
    vector<vector<int>> cdist(N, vector<int>(M, -1));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == '*') {
        q.push({i, j});
        cdist[i][j] = 0;
      }
    }

    while (!q.empty()) {
      auto [i, j] = q.front(); q.pop();
      for (int d = 0; d < 4; ++d) {
        int ni = i + dx[d], nj = j + dy[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= M || grid[ni][nj] == 'X' || cdist[ni][nj] != -1) continue;
        cdist[ni][nj] = cdist[i][j] + 1;
        if (grid[ni][nj] == '#') return cdist[ni][nj];
        q.push({ni, nj});
      }
    }
    return -1;
  }
};
