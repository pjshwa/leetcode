const int MOD = 1e9 + 7;

class Solution {
  bool is_prime(char c) {
    return c == '2' || c == '3' || c == '5' || c == '7';
  }

public:
  int beautifulPartitions(string s, int k, int minLength) {
    if (!is_prime(s[0]) || is_prime(s.back())) return 0;

    vector<int> G;
    for (int i = 1; i < s.size(); ++i) {
      if (!is_prime(s[i - 1]) && is_prime(s[i])) G.push_back(i);
    }
    G.push_back(s.size());

    int Z = G.size();
    int dp[Z + 1][k + 1];
    memset(dp, 0, sizeof dp); dp[0][0] = 1;

    for (int i = 1; i <= Z; ++i) {
        
      int l = 0, r = i;
      while (l < r) {
        int m = (l + r) / 2;

        int len = G[i - 1] - (m ? G[m - 1] : 0);
        if (len >= minLength) l = m + 1;
        else r = m;
      }

      for (int j = 1; j <= k; ++j) {
        if (l) dp[i][j] = dp[l - 1][j - 1];
      }
      for (int j = 0; j <= k; ++j) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
      }
    }

    return (dp[Z][k] - dp[Z - 1][k] + MOD) % MOD;
  }
};
