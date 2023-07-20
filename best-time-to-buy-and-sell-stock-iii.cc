const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();

    int d[N][5];
    for (int i = 0; i < N; i++) for (int j = 0; j < 5; j++) d[i][j] = -INF;

    d[0][0] = d[0][2] = d[0][4] = 0; d[0][1] = d[0][3] = -prices[0];
    for (int i = 1; i < N; i++) {
      for (int j = 0; j < 5; j++) d[i][j] = d[i - 1][j];
      for (int j = 1; j < 5; j++) {
        if (j & 1) d[i][j] = max(d[i][j], d[i - 1][j - 1] - prices[i]);
        else d[i][j] = max(d[i][j], d[i - 1][j - 1] + prices[i]);
      }
    }

    int ans = 0;
    for (int i = 0; i < 5; i += 2) ans = max(ans, d[N - 1][i]);
    return ans;
  }
};
