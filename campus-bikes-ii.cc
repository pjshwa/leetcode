class Solution {
public:
  int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
    int N = workers.size(), M = bikes.size();

    vector<vector<int>> dp(N + 1, vector<int>(1 << M, 0x3f3f3f3f));
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) for (int s = 1; s < (1 << M); ++s) {
      for (int j = 0; j < M; ++j) if (s & (1 << j)) {
        int prev = s ^ (1 << j);
        int cost = abs(workers[i - 1][0] - bikes[j][0]) + abs(workers[i - 1][1] - bikes[j][1]);
        dp[i][s] = min(dp[i][s], dp[i - 1][prev] + cost);
      }
    }
    return *min_element(dp[N].begin(), dp[N].end());
  }
};
