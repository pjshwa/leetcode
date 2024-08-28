const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int N = grid1.size(), M = grid1[0].size();
    vector<vector<int>> vis(N, vector<int>(M, 0)); int ok;
    function<void(int, int)> dfs = [&](int x, int y) {
      vis[x][y] = 1; ok &= grid1[x][y];
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M || vis[nx][ny] || !grid2[nx][ny]) continue;
        dfs(nx, ny);
      }
    };

    int ans = 0;
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) {
      if (vis[i][j] || !grid2[i][j]) continue;
      ok = 1; dfs(i, j);
      ans += ok;
    }
    return ans;
  }
};
