class Solution {
public:
  int minimumOperations(vector<int>& nums) {
    int n = nums.size(), ans = 0;

    int dp[n][4]; memset(dp, 0x3f, sizeof(dp));
    for (int j = 1; j <= 3; j++) {
      dp[0][j] = nums[0] == j ? 0 : 1;
    }
    for (int i = 1; i < n; i++) {
      for (int nj = 1; nj <= 3; nj++) for (int pj = 1; pj <= nj; pj++) {
        dp[i][nj] = min(dp[i][nj], dp[i - 1][pj] + (nums[i] == nj ? 0 : 1));
      }
    }

    return min(dp[n - 1][1], min(dp[n - 1][2], dp[n - 1][3]));
  }
};
