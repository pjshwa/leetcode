using ll = long long;

class Solution {
public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    ll N = grid.size(), M = grid[0].size(), sum = 0;
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) sum += grid[i][j];
    if (sum & 1) return false;

    vector<vector<ll>> P(N + 1, vector<ll>(M + 1));
    for (int i = 1; i <= N; ++i) for (int j = 1; j <= M; ++j) {
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + grid[i - 1][j - 1];
    }

    for (int i = 1; i <= N; ++i) if (P[i][M] * 2 == sum) return true;
    for (int j = 1; j <= M; ++j) if (P[N][j] * 2 == sum) return true;
    return false;      
  }
};
