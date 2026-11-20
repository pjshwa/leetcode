class Solution {
public:
  int maxSelectedElements(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int maxv = nums.back(), ans = 1;
    vector<int> freq(maxv + 10, 0);
    for (int e : nums) ++freq[e];

    vector<vector<int>> dp(maxv + 10, vector<int>(2, 0));
    for (int v = 1; v <= maxv + 1; ++v) {
      if (freq[v] > 0) dp[v][0] = max(dp[v - 1][0], dp[v - 1][1]) + 1;
      if (freq[v - 1] > 0) dp[v][1] = dp[v - 1][1] + 1;
      if (freq[v - 1] > 1) dp[v][1] = max(dp[v][1], dp[v - 1][0] + 1);
      ans = max(ans, max(dp[v][0], dp[v][1]));
    }
    return ans;
  }
};
 