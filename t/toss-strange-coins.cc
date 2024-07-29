class Solution {
public:
  double probabilityOfHeads(vector<double>& prob, int target) {
    int N = prob.size();
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= N; ++i) {
      double p = prob[i - 1];
      for (int t = 0; t <= N; ++t) dp[i][t] += dp[i - 1][t] * (1 - p);
      for (int t = 1; t <= N; ++t) dp[i][t] += dp[i - 1][t - 1] * p;
    }
    return dp[N][target];
  }
};
