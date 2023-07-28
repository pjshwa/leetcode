using ll = long long;

class Solution {
public:
  long long maxScore(vector<int>& nums, int x) {
    int N = nums.size();
    ll dp[N][2];
    for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = -1e18;

    if (nums[0] & 1) dp[0][1] = nums[0];
    else dp[0][0] = nums[0];

    for (int i = 1; i < N; i++) {
      if (nums[i] & 1) {
        dp[i][1] = max(dp[i - 1][1] + nums[i], dp[i - 1][0] + nums[i] - x);
        dp[i][0] = dp[i - 1][0];
      }
      else {
        dp[i][1] = dp[i - 1][1];
        dp[i][0] = max(dp[i - 1][0] + nums[i], dp[i - 1][1] + nums[i] - x);
      }
    }

    return max(dp[N - 1][0], dp[N - 1][1]);
  }
};
