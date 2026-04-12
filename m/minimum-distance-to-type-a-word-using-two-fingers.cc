const int MAXN = 300, INF = 0x3f3f3f3f;

class Solution {
  int X[26], Y[26], dp[MAXN][27];

  int get_d(int s, int t) {
    if (s == 26) return 0;
    return abs(X[s] - X[t]) + abs(Y[s] - Y[t]);
  }

public:
  int minimumDistance(string word) {
    int a = 0, N = word.size(), ans = INF;
    for (int i = 0; i < 26; ++i) X[i] = i / 6, Y[i] = i % 6;

    memset(dp, 0x3f, sizeof(dp)); dp[0][26] = 0;
    for (int i = 1; i < N; ++i) {
      int s = word[i - 1] - 'A', t = word[i] - 'A';
      for (int j = 0; j <= 26; ++j) dp[i][j] = dp[i - 1][j] + get_d(s, t);
      for (int p = 0; p <= 26; ++p) {
        dp[i][s] = min(dp[i][s], dp[i - 1][p] + get_d(p, t));
      }
    }
    for (int i = 0; i <= 26; ++i) ans = min(ans, dp[N - 1][i]);
    return ans;
  }
};
