const int MOD = 1e9 + 7;

class Solution {
public:
  int lengthAfterTransformations(string s, int t) {
    int dp[2][26] = {0}, N = s.size();
    for (char& c : s) ++dp[0][c - 'a'];
    for (int i = 1; i <= t; ++i) {
      int x = i & 1;
      for (int j = 1; j < 26; ++j) dp[x][j] = dp[x ^ 1][j - 1];
      dp[x][0] = dp[x ^ 1][25];
      dp[x][1] = (dp[x][1] + dp[x ^ 1][25]) % MOD;
    }
    int ans = 0;
    for (int j = 0; j < 26; ++j) ans = (ans + dp[t & 1][j]) % MOD;
    return ans;
  }
};
