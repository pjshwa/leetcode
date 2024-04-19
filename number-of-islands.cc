const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<bool>> vis(N, vector<bool>(M, false));

    function<void(int, int)> dfs = [&](int x, int y) {
      vis[x][y] = true;
      for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (grid[nx][ny] == '0' || vis[nx][ny]) continue;
        dfs(nx, ny);
      }
    };

    int ans = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      if (grid[i][j] == '1' && !vis[i][j]) {
        dfs(i, j);
        ++ans;
      }
    }
    return ans;
  }
};
