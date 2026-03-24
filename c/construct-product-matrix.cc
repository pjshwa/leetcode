const int MOD = 12345;

class Solution {
public:
  vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<int>> ans(N, vector<int>(M));

    long long p = 1, s = 1;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      ans[i][j] = p;
      p = (p * grid[i][j]) % MOD;
    }
    for (int i = N - 1; i >= 0; --i) for (int j = M - 1; j >= 0; --j) {
      ans[i][j] = (ans[i][j] * s) % MOD;
      s = (s * grid[i][j]) % MOD;
    }
    return ans;
  }
};
