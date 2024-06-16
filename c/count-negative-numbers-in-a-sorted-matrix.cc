class Solution {
public:
  int countNegatives(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0, p = 0;
    for (int i = 0; i < n; i++) {
      while (p < m && grid[i][m - 1 - p] < 0) p++;
      ans += p;
    }
    return ans;
  }
};
