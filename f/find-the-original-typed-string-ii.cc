using ll = long long;
const int MAXN = 5e5, MOD = 1e9 + 7;

class Solution {

public:
  int possibleStringCount(string word, int k) {

    vector<int> W; ll streak = 1, N = word.size(), tot = 1;
    for (int i = 1; i < N; ++i) {
      if (word[i] == word[i - 1]) ++streak;
      else {
        W.push_back(streak);
        tot = (tot * streak) % MOD;
        streak = 1;
      }
    }
    W.push_back(streak);
    tot = (tot * streak) % MOD;
    if (k <= W.size()) return tot;

    vector<vector<ll>> dp(W.size() + 1, vector<ll>(k + 1, 0));
    for (int nk = 0; nk <= k; ++nk) dp[0][nk] = 1;
    for (int i = 1; i <= W.size(); ++i) {
      int e = W[i - 1];
      for (int nk = 1; nk <= k; ++nk) {
        dp[i][nk] = (dp[i - 1][nk - 1] - (nk > e ? dp[i - 1][nk - e - 1] : 0) + MOD) % MOD;
      }
      for (int nk = 1; nk <= k; ++nk) dp[i][nk] = (dp[i][nk] + dp[i][nk - 1]) % MOD;
    }

    ll rem = dp[W.size()][k - 1];
    return (tot - rem + MOD) % MOD;
  }
};
