const int MAXN = 1000, INF = 1e9 + 7;

class Solution {
  int dp[MAXN][MAXN];

public:
  int maxCollectedFruits(vector<vector<int>>& fruits) {
    int N = fruits.size(), ans = 0;
    for (int i = 0; i < N; ++i) {
      ans += fruits[i][i];
      fruits[i][i] = 0;
    }

    function<int(int, int)> rec1 = [&](int i, int u) {
      if (i == N - 1) return u == 0 ? 0 : -INF;
      if (dp[i][u] != -1) return dp[i][u];
      int res = max(rec1(i + 1, u), rec1(i + 1, u + 1));
      if (u > 0) res = max(res, rec1(i + 1, u - 1));
      return dp[i][u] = res + fruits[N - 1 - u][i];
    };
    function<int(int, int)> rec2 = [&](int i, int u) -> int {
      if (i == N - 1) return u == 0 ? 0 : -INF;
      if (dp[i][u] != -1) return dp[i][u];
      int res = max(rec2(i + 1, u), rec2(i + 1, u + 1));
      if (u > 0) res = max(res, rec2(i + 1, u - 1));
      return dp[i][u] = res + fruits[i][N - 1 - u];
    };

    memset(dp, -1, sizeof(dp));
    ans += rec1(0, 0);
    memset(dp, -1, sizeof(dp));
    ans += rec2(0, 0);
    return ans;
  }
};
