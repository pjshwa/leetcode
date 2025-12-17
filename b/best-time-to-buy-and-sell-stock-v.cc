using ll = long long;

class Solution {
public:
  long long maximumProfit(vector<int>& prices, int k) {
    int N = prices.size();
    vector<vector<vector<ll>>> dp(
        N + 1, vector<vector<ll>>(k + 1, vector<ll>(3, -1e18)));

    dp[0][0][0] = 0;
    for (int i = 1; i <= N; ++i) {
      int price = prices[i - 1];
      for (int j = 0; j <= k; ++j) {
        dp[i][j][0] = max({
          dp[i - 1][j][0], dp[i - 1][j][1] + price, dp[i - 1][j][2] - price});
        dp[i][j][1] = dp[i - 1][j][1];
        dp[i][j][2] = dp[i - 1][j][2];
      }
      for (int j = 1; j <= k; ++j) {
        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - price);
        dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][0] + price);
      }
    }

    ll ans = 0;
    for (int j = 0; j <= k; ++j) ans = max(ans, dp[N][j][0]);
    return ans;
  }
};
