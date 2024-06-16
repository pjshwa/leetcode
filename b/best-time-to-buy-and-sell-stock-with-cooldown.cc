const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> a(n, -INF), d(n);

    for (int i = 0; i < n; i++) {
      if (i) a[i] = a[i - 1], d[i] = d[i - 1];
      a[i] = max(a[i], -prices[i]);
      if (i >= 2) {
        a[i] = max(a[i], d[i - 2] - prices[i]);
      }

      d[i] = max(d[i], a[i] + prices[i]);
    }
    return d[n - 1];
  }
};
