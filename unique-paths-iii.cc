const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

class Solution {
  int n, m, ei, ej, tot = 0, cur = 0, ans = 0;
  bool vis[20][20] = {0};

  void dfs(int i, int j) {
    vis[i][j] = true; cur++;
    if (i == ei && j == ej) {
      if (cur == tot) ans++;
    }
    else {
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) continue;
        dfs(x, y);
      }

    }
    vis[i][j] = false; cur--;
  }


public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    n = grid.size(), m = grid[0].size();

    int si, sj;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      if (grid[i][j] == 1) si = i, sj = j;
      if (grid[i][j] == 2) ei = i, ej = j;

      if (grid[i][j] == -1) vis[i][j] = true;
      else tot++;
    }

    dfs(si, sj);
    return ans;
  }
};
