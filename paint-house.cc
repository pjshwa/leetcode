class Solution {
public:
  int minCost(vector<vector<int>>& costs) {
    int N = costs.size();

    vector<vector<int>> dp(N, vector<int>(3, INT_MAX));
    for (int j = 0; j < 3; ++j) dp[0][j] = costs[0][j];

    for (int i = 1; i < N; ++i) {
      for (int pj = 0; pj < 3; ++pj) for (int nj = 0; nj < 3; ++nj) {
        if (pj == nj) continue;
        dp[i][nj] = min(dp[i][nj], dp[i - 1][pj] + costs[i][nj]);
      }
    }

    int ans = INT_MAX;
    for (int j = 0; j < 3; ++j) ans = min(ans, dp[N - 1][j]);
    return ans;
  }
};
