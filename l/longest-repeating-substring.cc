class Solution {
public:
  int longestRepeatingSubstring(string s) {
    int N = s.size(), ans = 0;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; ++i) for (int j = 1; j < i; ++j) {
      if (s[i - 1] == s[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
      ans = max(ans, dp[i][j]);
    }
    return ans;
  }
};
