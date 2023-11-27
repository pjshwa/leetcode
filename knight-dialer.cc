const int MOD = 1e9 + 7;
using pii = pair<int, int>;

class Solution {
public:
  int knightDialer(int n) {
    vector<pii> pos = {
      {3, 1}, {3, 2}, {3, 3},
      {2, 1}, {2, 2}, {2, 3},
      {1, 1}, {1, 2}, {1, 3},
      {4, 2}
    };

    int dp[2][10];
    for (int i = 0; i < 10; ++i) dp[1][i] = 1;

    for (int t = 2; t <= n; ++t) {
      int x = t & 1;
      memset(dp[x], 0, sizeof(dp[x]));

      for (int pj = 0; pj < 10; ++pj) for (int nj = 0; nj < 10; ++nj) {
        auto [px, py] = pos[pj]; auto [nx, ny] = pos[nj];

        int dx = abs(px - nx), dy = abs(py - ny);
        if (dx == 1 && dy == 2 || dx == 2 && dy == 1) {
          dp[x][nj] = (dp[x][nj] + dp[x ^ 1][pj]) % MOD;
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < 10; ++i) ans = (ans + dp[n & 1][i]) % MOD;
    return ans;
  }
};
