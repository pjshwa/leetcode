const int INF = 0x3f3f3f3f;

class Solution {
  int d[1001][101];
public:
  int maxProfit(int k, vector<int>& prices) {
    memset(d, 0, sizeof(d));

    int n = prices.size();
    for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) d[i][j] = -INF;
    d[0][0] = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= k; j++) d[i][j] = d[i - 1][j];
      for (int j = 1; j <= k; j++) for (int l = 0; l < i; l++) {
        if (prices[i - 1] <= prices[l]) continue;
        d[i][j] = max(d[i][j], d[l][j - 1] + prices[i - 1] - prices[l]);
      }
    }

    int ans = 0;
    for (int i = 0; i <= k; i++) ans = max(ans, d[n][i]);
    return ans;
  }
};
