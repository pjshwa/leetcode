using ll = long long;

class Solution {
public:
  long long minIncrementOperations(vector<int>& nums, int k) {
    int n = nums.size();
    vector<ll> dp(n, 1e18);
    for (int j = 0; j < 3; ++j) {
      dp[j] = max(0, k - nums[j]);
    }

    for (int j = 3; j < n; ++j) {
      ll cost = max(0, k - nums[j]);
      for (int l = 1; l <= 3; ++l) dp[j] = min(dp[j], dp[j - l] + cost);
    }

    ll ans = 1e18;
    for (int i = n - 3; i < n; ++i) ans = min(ans, dp[i]);
    return ans;
  }
};
