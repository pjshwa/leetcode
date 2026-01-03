const int MAXN = 5000, MOD = 1e9 + 7;

class Solution {
  int dp[MAXN][3][3][3];

public:
  int numOfWays(int n) {
    for (int c1 = 0; c1 < 3; ++c1) for (int c2 = 0; c2 < 3; ++c2) for (int c3 = 0; c3 < 3; ++c3) {
      if (c1 == c2 || c2 == c3) continue;
      dp[0][c1][c2][c3] = 1;
    }
    for (int i = 1; i < n; ++i) {
      for (int c1 = 0; c1 < 3; ++c1) for (int c2 = 0; c2 < 3; ++c2) for (int c3 = 0; c3 < 3; ++c3)
      for (int n1 = 0; n1 < 3; ++n1) for (int n2 = 0; n2 < 3; ++n2) for (int n3 = 0; n3 < 3; ++n3) {
        if (c1 == c2 || c2 == c3) continue;
        if (n1 == n2 || n2 == n3) continue;
        if (c1 == n1 || c2 == n2 || c3 == n3) continue;
        dp[i][n1][n2][n3] = (dp[i][n1][n2][n3] + dp[i - 1][c1][c2][c3]) % MOD;
      }
    }

    int ans = 0;
    for (int c1 = 0; c1 < 3; ++c1) for (int c2 = 0; c2 < 3; ++c2) for (int c3 = 0; c3 < 3; ++c3) {
      if (c1 == c2 || c2 == c3) continue;
      ans = (ans + dp[n - 1][c1][c2][c3]) % MOD;
    }
    return ans;
  }
};
