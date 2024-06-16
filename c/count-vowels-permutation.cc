const int MOD = 1e9 + 7;

class Solution {
public:
  int countVowelPermutation(int n) {
    vector<vector<int>> g = {{1, 2, 4}, {0, 2}, {1, 3}, {2}, {2, 3}};
    vector<vector<int>> dp(n + 1, vector<int>(5));
    for (int i = 0; i < 5; i++) dp[1][i] = 1;
    for (int j = 2; j <= n; j++) {
      for (int i = 0; i < 5; i++) {
        for (int k : g[i]) dp[j][i] = (dp[j][i] + dp[j - 1][k]) % MOD;
      }
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) ans = (ans + dp[n][i]) % MOD;
    return ans;
  }
};
