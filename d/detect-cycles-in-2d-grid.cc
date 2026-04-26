const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

class Solution {
  int N, M, ok = 0;

  void dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid, vector<vector<int>>& visited) {
    if (ok) return;
    visited[i][j] = 1;
    for (int k = 0; k < 4; ++k) {
      int x = i + dx[k], y = j + dy[k];
      if (x < 0 || x >= N || y < 0 || y >= M || grid[x][y] != grid[i][j]) continue;
      if (visited[x][y]) {
        if (x != pi || y != pj) ok = 1;
        continue;
      }
      dfs(x, y, i, j, grid, visited);
    }
  }

public:
  bool containsCycle(vector<vector<char>>& grid) {
    N = grid.size(), M = grid[0].size();
    vector<vector<int>> visited(N, vector<int>(M));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (visited[i][j]) continue;
      dfs(i, j, -1, -1, grid, visited);
      if (ok) return true;
    }
    return false;
  }
};
