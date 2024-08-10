const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

class Solution {
public:
  int regionsBySlashes(vector<string>& grid) {
    int N = grid.size();
    vector<vector<int>> G(3 * N, vector<int>(3 * N, 0));
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (grid[i][j] == '/') {
        G[3 * i][3 * j + 2] = G[3 * i + 1][3 * j + 1] = G[3 * i + 2][3 * j] = 1;
      } else if (grid[i][j] == '\\') {
        G[3 * i][3 * j] = G[3 * i + 1][3 * j + 1] = G[3 * i + 2][3 * j + 2] = 1;
      }
    }

    vector<vector<int>> vis(3 * N, vector<int>(3 * N, 0)); int ans = 0;
    auto oob = [&](int i, int j) { return i < 0 || i >= 3 * N || j < 0 || j >= 3 * N; };
    function<void(int, int)> dfs = [&](int i, int j) {
      vis[i][j] = 1;
      for (int d = 0; d < 4; ++d) {
        int ni = i + dx[d], nj = j + dy[d];
        if (oob(ni, nj) || vis[ni][nj] || G[ni][nj]) continue;
        dfs(ni, nj);
      }
    };

    for (int i = 0; i < 3 * N; ++i) for (int j = 0; j < 3 * N; ++j) {
      if (!vis[i][j] && !G[i][j]) ++ans, dfs(i, j);
    }
    return ans;
  }
};
