class Solution {
public:
  int minSwaps(vector<vector<int>>& grid) {
    int N = grid.size(), ans = 0;
    for (int t = 0; t < N; ++t) {
      int i = t;
      for (; i < N; ++i) {
        int j = N - 1;
        for (; j >= 0; --j) {
          if (grid[i][j] == 1) break;
        }
        if (t >= j) break;
      }
      if (i == N) return -1;
      for (int k = i; k > t; --k) {
        swap(grid[k], grid[k - 1]);
        ++ans;
      }
    }
    return ans;
  }
};
