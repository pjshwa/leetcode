#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfSets(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) for (int j = 0; j <= 2 * k; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
      if (j > 1 && (j & 1)) dp[i][j] = (dp[i][j] + dp[i - 1][j - 2]) % MOD;
    }
    return dp[n][2 * k];
  }
};
