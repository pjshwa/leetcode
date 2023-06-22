class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int N = prices.size();

    int d[N][2];
    d[0][0] = 0; d[0][1] = -prices[0];
    for (int i = 1; i < N; i++) {
      d[i][0] = max(d[i - 1][0], d[i - 1][1] + prices[i] - fee);
      d[i][1] = max(d[i - 1][1], d[i - 1][0] - prices[i]);
    }
    return d[N - 1][0];
  }
};
