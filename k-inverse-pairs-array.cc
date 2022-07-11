const int MOD = 1e9 + 7;

class Solution {
  int d[1001][1001];
public:
  int kInversePairs(int n, int k) {
    for (int i = 1; i <= n; i++) for (int j = 0; j <= k; j++) {
      if (j == 0) d[i][j] = 1;
      else {
        int val = (d[i - 1][j] + MOD - ((j - i) >= 0 ? d[i - 1][j - i] : 0)) % MOD;
        d[i][j] = (d[i][j - 1] + val) % MOD;
      }
    }
    return ((d[n][k] + MOD - (k > 0 ? d[n][k - 1] : 0)) % MOD);
  }
};
