class Solution {
public:
  int maxSumAfterOperation(vector<int>& nums) {
    int N = nums.size();
    int dp[N][2], ans = nums[0] * nums[0]; memset(dp, 0, sizeof(dp));
    dp[0][0] = nums[0]; dp[0][1] = nums[0] * nums[0];
    for (int i = 1; i < N; ++i) {
      dp[i][0] = max(nums[i], dp[i - 1][0] + nums[i]);
      dp[i][1] = max({nums[i] * nums[i], dp[i - 1][0] + nums[i] * nums[i], dp[i - 1][1] + nums[i]});
      ans = max(ans, dp[i][1]);
    }
    return ans;
  }
};
