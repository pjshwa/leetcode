using ll = long long;
const int MAXN = 80, MOD = 1e9 + 7;

class Solution {
public:
  int countBalancedPermutations(string num) {
    int sum = 0, N = num.size();
    vector<vector<ll>> C(N + 1, vector<ll>(N + 1)); C[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
      C[i][0] = C[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
      }
    }

    vector<int> P(10);
    for (char c : num) {
      int d = c - '0';
      sum += d; ++P[d];
    }
    if (sum & 1) return 0;

    int T = sum / 2, V = (N + 1) / 2;
    vector<vector<vector<int>>> dp(10, vector<vector<int>>(V + 1, vector<int>(T + 1)));

    int used = 0;
    for (int i = 0; i < 10; ++i) {
      int tot = P[i];
      for (int cnt = 0; cnt <= tot; ++cnt) {
        int d = cnt * i;
        for (int j = V; j >= cnt; --j) for (int k = T; k >= d; --k) {
          int ov = V - (j - cnt), eu = used - (j - cnt);
          int ev = N - V - eu;
          if (ov < 0 || ev < 0) continue;

          ll val = C[ov][cnt] * C[ev][tot - cnt] % MOD;
          if (i == 0) {
            if (j == cnt && k == d) {
              dp[i][j][k] = (dp[i][j][k] + val) % MOD;
            }
          }
          else {
            val = (val * dp[i - 1][j - cnt][k - d]) % MOD;
            dp[i][j][k] = (dp[i][j][k] + val) % MOD;
          }
        }
      }
      used += P[i];
    }

    return dp[9][V][T];
  }
};
