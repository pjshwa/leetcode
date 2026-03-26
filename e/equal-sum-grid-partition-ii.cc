using ll = long long;
const int MAXN = 1e5;

class Solution {
public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    ll N = grid.size(), M = grid[0].size(), sum = 0;
    vector<int> C(MAXN + 1);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      sum += grid[i][j];
      ++C[grid[i][j]];
    }

    vector<vector<ll>> P(N + 1, vector<ll>(M + 1));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + grid[i - 1][j - 1];
    }

    vector<int> L(MAXN + 1), R = C;
    auto get = [&](vector<int>& A, ll d) {
      if (d < 0 || d > MAXN) return 0;
      return A[d];
    };

    for (int i = 1; i < N; ++i) {
      ll a = P[i][M], b = sum - a;
      if (a == b) return true;

      for (int j = 0; j < M; ++j) {
        int x = grid[i - 1][j];
        --R[x]; ++L[x];
      }
      if (a > b) {
        ll d = a - b;
        if (grid[i - 1][0] == d || grid[i - 1][M - 1] == d) return true;
        if (grid[0][0] == d || grid[0][M - 1] == d) return true;
        if (M > 1 && i > 1 && get(L, d) > 0) return true;
      } else {
        ll d = b - a;
        if (grid[i][0] == d || grid[i][M - 1] == d) return true;
        if (grid[N - 1][0] == d || grid[N - 1][M - 1] == d) return true;
        if (M > 1 && i < N - 1 && get(R, d) > 0) return true;
      }
    }

    L.assign(MAXN + 1, 0); R = C;
    for (int j = 1; j < M; ++j) {
      ll a = P[N][j], b = sum - a;
      if (a == b) return true;

      for (int i = 0; i < N; ++i) {
        int x = grid[i][j - 1];
        --R[x]; ++L[x];
      }
      if (a > b) {
        ll d = a - b;
        if (grid[0][j - 1] == d || grid[N - 1][j - 1] == d) return true;
        if (grid[0][0] == d || grid[N - 1][0] == d) return true;
        if (N > 1 && j > 1 && get(L, d) > 0) return true;
      } else {
        ll d = b - a;
        if (grid[0][j] == d || grid[N - 1][j] == d) return true;
        if (grid[0][M - 1] == d || grid[N - 1][M - 1] == d) return true;
        if (N > 1 && j < M - 1 && get(R, d) > 0) return true;
      }
    }
    return false;
  }
};
