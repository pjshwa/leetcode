using ll = long long;
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

class Solution {
public:
  long long sumRemoteness(vector<vector<int>>& grid) {
    ll N = grid.size(), tot = 0, ans = 0, sum, cnt;
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (grid[i][j] != -1) tot += grid[i][j];
    }
    function<void(int, int)> dfs = [&](int i, int j) {
      sum += grid[i][j]; ++cnt;
      grid[i][j] = -1;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dx[k], nj = j + dy[k];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N || grid[ni][nj] == -1) continue;
        dfs(ni, nj);
      }
    };
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) {
      if (grid[i][j] == -1) continue;
      sum = cnt = 0;
      dfs(i, j);
      ans += cnt * (tot - sum);
    }
    return ans;
  }
};
