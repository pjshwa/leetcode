class Solution {
public:
  int maximizeWin(vector<int>& prizePositions, int k) {
    int N = prizePositions.size(); ++k;

    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    for (int i = 1; i <= N; ++i) {
      for (int j = 0; j < 3; ++j) {
        dp[i][j] = dp[i - 1][j];
      }

      int x = prizePositions[i - 1];
      auto it = upper_bound(prizePositions.begin(), prizePositions.end(), x - k);
      int j = it - prizePositions.begin();
      dp[i][1] = max(dp[i][1], dp[j][0] + i - j);
      dp[i][2] = max(dp[i][2], dp[j][1] + i - j);
    }

    return dp[N][2];
  }
};
