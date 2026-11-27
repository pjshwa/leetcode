class Solution {
public:
  int maximumSaleItems(vector<vector<int>>& items, int budget) {
    int N = items.size(); vector<int> bonus(N);
    for (int i = 0; i < N; ++i) {
      int f = items[i][0];
      for (int j = 0; j < N; ++j) {
        int g = items[j][0];
        if (g % f == 0) ++bonus[i];
      }
    }

    int minp = INT_MAX; vector<vector<int>> dp(N + 1, vector<int>(budget + 1, 0));
    for (int i = 1; i <= N; ++i) {
      int p = items[i - 1][1], a = bonus[i - 1]; minp = min(minp, p);
      for (int v = 0; v <= budget; ++v) dp[i][v] = dp[i - 1][v];
      for (int v = p; v <= budget; ++v) dp[i][v] = max(dp[i][v], dp[i - 1][v - p] + a);
    }
    int ans = 0;
    for (int v = 0; v <= budget; ++v) ans = max(ans, dp[N][v] + (budget - v) / minp);
    return ans;
  }
};
