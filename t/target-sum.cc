const int MAXV = 2500, BIAS = 1000;

class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int N = nums.size();

    vector<vector<int>> dp(N, vector<int>(MAXV + 1, 0));
    dp[0][nums[0] + BIAS] += 1;
    dp[0][-nums[0] + BIAS] += 1;
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j <= MAXV; ++j) {
        if (j + nums[i] <= MAXV) dp[i][j] += dp[i - 1][j + nums[i]];
        if (j - nums[i] >= 0) dp[i][j] += dp[i - 1][j - nums[i]];
      }
    }

    return dp[N - 1][target + BIAS];
  }
};
