class Solution {
  bool check(vector<vector<int>>& grid, int z) {
    int N = grid.size(), M = grid[0].size();
    for (int i = 0; i <= N - z; ++i) for (int j = 0; j <= M - z; ++j) {
      int t = 0;
      for (int k = 0; k < z; ++k) t += grid[i][j + k];

      int ok = 1;
      for (int pi = 0; pi < z; ++pi) {
        int sum = 0;
        for (int pj = 0; pj < z; ++pj) sum += grid[i + pi][j + pj];
        ok &= (sum == t);
      }
      for (int pj = 0; pj < z; ++pj) {
        int sum = 0;
        for (int pi = 0; pi < z; ++pi) sum += grid[i + pi][j + pj];
        ok &= (sum == t);
      }
      for (int di = 0; di < z; ++di) {
        int sum1 = 0, sum2 = 0;
        for (int d = 0; d < z; ++d) {
          sum1 += grid[i + d][j + d];
          sum2 += grid[i + d][j + z - 1 - d];
        }
        ok &= (sum1 == t);
        ok &= (sum2 == t);
      }
      if (ok) return true;
    }
    return false;
  }

public:
  int largestMagicSquare(vector<vector<int>>& grid) {
    for (int z = min(grid.size(), grid[0].size()); z >= 2; --z) {
      if (check(grid, z)) return z;
    }
    return 1;
  }
};
