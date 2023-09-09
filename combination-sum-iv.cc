using ll = long long;
const ll MOD = 1e10;

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    ll dp[target + 1]; dp[0] = 1;
    for (int v = 1; v <= target; ++v) {
      dp[v] = 0;
      for (int e : nums) {
        if (v >= e) dp[v] = (dp[v] + dp[v - e]) % MOD;
      }
    }
    return (int)dp[target];
  }
};
