class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();

    auto is_magic = [&](int x, int y) {
      vector<int> cnt(10);
      for (int i = x; i < x + 3; ++i) for (int j = y; j < y + 3; ++j) {
        if (grid[i][j] < 1 || grid[i][j] > 9) return false;
        cnt[grid[i][j]]++;
      }
      for (int i = 1; i <= 9; ++i) if (cnt[i] != 1) return false;

      set<int> sums;
      sums.insert(grid[x][y] + grid[x][y + 1] + grid[x][y + 2]);
      sums.insert(grid[x + 1][y] + grid[x + 1][y + 1] + grid[x + 1][y + 2]);
      sums.insert(grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2]);
      sums.insert(grid[x][y] + grid[x + 1][y] + grid[x + 2][y]);
      sums.insert(grid[x][y + 1] + grid[x + 1][y + 1] + grid[x + 2][y + 1]);
      sums.insert(grid[x][y + 2] + grid[x + 1][y + 2] + grid[x + 2][y + 2]);
      sums.insert(grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2]);
      sums.insert(grid[x][y + 2] + grid[x + 1][y + 1] + grid[x + 2][y]);

      return sums.size() == 1;
    };

    int ans = 0;
    for (int i = 0; i < N - 2; ++i) for (int j = 0; j < M - 2; ++j) {
      ans += is_magic(i, j);
    }
    return ans;
  }
};
