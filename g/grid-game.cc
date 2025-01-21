using ll = long long;

class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int N = grid[0].size();
    vector<vector<ll>> P(2, vector<ll>(N + 1));
    for (int i = 1; i <= N; ++i) {
      P[0][i] = P[0][i - 1] + grid[0][i - 1];
      P[1][i] = P[1][i - 1] + grid[1][i - 1];
    }

    ll ans = min(P[0][N] - P[0][1], P[1][N - 1]);
    for (int i = 2; i < N; ++i) {
      ans = min(ans, max(P[0][N] - P[0][i], P[1][i - 1]));
    }
    return ans;
  }
};
