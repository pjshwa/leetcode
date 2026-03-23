using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
  int maxProductPath(vector<vector<int>>& grid) {
    int N = grid.size(), M = grid[0].size();
    vector<vector<ll>> L(N, vector<ll>(M)), U(N, vector<ll>(M));
    L[0][0] = U[0][0] = grid[0][0];
    for (int i = 1; i < N; ++i) L[i][0] = U[i][0] = L[i - 1][0] * grid[i][0];
    for (int j = 1; j < M; ++j) L[0][j] = U[0][j] = L[0][j - 1] * grid[0][j];
    for (int i = 1; i < N; ++i) for (int j = 1; j < M; ++j) {
      ll maxu = max(U[i - 1][j], U[i][j - 1]), minl = min(L[i - 1][j], L[i][j - 1]);
      if (grid[i][j] >= 0) {
        L[i][j] = minl * grid[i][j];
        U[i][j] = maxu * grid[i][j];
      } else {
        L[i][j] = maxu * grid[i][j];
        U[i][j] = minl * grid[i][j];
      }
    }
    if (U[N - 1][M - 1] < 0) return -1;
    return U[N - 1][M - 1] % MOD;
  }
};
