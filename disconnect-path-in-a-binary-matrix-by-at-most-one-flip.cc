using pii = pair<int, int>;

class Solution {
  bool dfs1(int i, int j, int N, int M, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
    visited[i][j] = true;
    if (i == N - 1 && j == M - 2) return true;

    for (auto [ni, nj] : {pii(i + 1, j), pii(i, j + 1)}) {
      if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
      if (visited[ni][nj] || grid[ni][nj] == 0) continue;
      if (dfs1(ni, nj, N, M, visited, grid)) return true;
    }
    return false;
  }

  bool dfs2(int i, int j, int N, int M, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
    visited[i][j] = true;
    if (i == N - 2 && j == M - 1) return true;

    for (auto [ni, nj] : {pii(i, j + 1), pii(i + 1, j)}) {
      if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
      if (visited[ni][nj] || grid[ni][nj] == 0) continue;
      if (dfs2(ni, nj, N, M, visited, grid)) return true;
    }
    return false;
  }

public:
  bool isPossibleToCutPath(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    if (N == 1) return M >= 3;
    if (M == 1) return N >= 3;
    if (grid[0][1] == 0 || grid[1][0] == 0) return true;
    if (grid[N - 1][M - 2] == 0 || grid[N - 2][M - 1] == 0) return true;

    vector<vector<bool>> visited(N, vector<bool>(M));
    return !(dfs1(1, 0, N, M, visited, grid) && dfs2(0, 1, N, M, visited, grid));
  }
};
