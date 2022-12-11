class Solution {
public:
  int deleteGreatestValue(vector<vector<int>>& grid) {
    int ans = 0;
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int t = 0; t < m; t++) {
      int cur = 0;
      for (int i = 0; i < n; i++) {
        int r_cur = 0, r_idx = -1;
        for (int j = 0; j < m; j++) {
          if (vis[i][j]) continue;
          if (grid[i][j] > r_cur) {
            r_cur = grid[i][j];
            r_idx = j;
          }
        }

        vis[i][r_idx] = true;
        cur = max(cur, r_cur);
      }

      ans += cur;
    }

    return ans;
  }
};
