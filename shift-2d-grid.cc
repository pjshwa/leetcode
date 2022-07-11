class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
      int u = i * m + j;
      u = (u + k) % (n * m);
      int x = u / m, y = u % m;
      ans[x][y] = grid[i][j];
    }
    return ans;
  }
};
