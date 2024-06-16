const int MAX = 201, MOD = 1e9 + 7;

class Solution {
  int dp[MAX][MAX], N;

  // dp[u][i] = i-th element is u
  int rec(int u, int i, string& s) {
    if (i == s.size()) return 1;
    if (dp[u][i] != -1) return dp[u][i];

    int ret = 0;
    if (s[i] == 'D') {
      for (int nu = 0; nu < u; ++nu) {
        ret = (ret + rec(nu, i + 1, s)) % MOD;
      }
    }
    else {
      for (int nu = u + 1; nu < N - i; ++nu) {
        ret = (ret + rec(nu - 1, i + 1, s)) % MOD;
      }
    }

    return dp[u][i] = ret;
  }

public:
  int numPermsDISequence(string s) {
    N = s.size() + 1;

    memset(dp, -1, sizeof dp); int ret = 0;
    for (int u = 0; u < N; ++u) ret = (ret + rec(u, 0, s)) % MOD;
    return ret;
  }
};
