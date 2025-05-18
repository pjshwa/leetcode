const int MOD = 1e9 + 7;

bool isValid(int mask, int m) {
  int C[m];
  for (int i = 0; i < m; ++i) {
    C[i] = mask % 3;
    mask /= 3;
  }
  for (int i = 0; i < m - 1; ++i) {
    if (C[i] == C[i + 1]) return false;
  }
  return true;
}

bool isCompat(int mask1, int mask2, int m) {
  for (int i = 0; i < m; ++i) {
    if (mask1 % 3 == mask2 % 3) return false;
    mask1 /= 3;
    mask2 /= 3;
  }
  return true;
}

class Solution {
public:
  int colorTheGrid(int m, int n) {
    int mask = 1;
    for (int i = 0; i < m; ++i) mask *= 3;

    vector<int> vmasks;
    for (int i = 0; i < mask; ++i) {
      if (isValid(i, m)) vmasks.push_back(i);
    }
    vector<vector<int>> dp(mask, vector<int>(n, 0));
    for (int cm : vmasks) dp[cm][0] = 1;

    for (int j = 1; j < n; ++j) {
      for (int pm : vmasks) for (int cm : vmasks) {
        if (isCompat(pm, cm, m)) dp[cm][j] = (dp[cm][j] + dp[pm][j - 1]) % MOD;
      }
    }
    int ans = 0;
    for (int cm : vmasks) {
      ans = (ans + dp[cm][n - 1]) % MOD;
    }
    return ans;
  }
};
