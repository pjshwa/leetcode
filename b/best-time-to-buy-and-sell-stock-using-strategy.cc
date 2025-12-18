using ll = long long;

class Solution {
public:
  long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    int N = prices.size(), h = k / 2;
    vector<ll> PP(N + 1, 0), SP(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
      ll p = prices[i - 1], s = strategy[i - 1];
      PP[i] = PP[i - 1] + p;
      SP[i] = SP[i - 1] + s * p;
    }

    ll ans = SP[N];
    for (int i = k; i <= N; ++i) {
      ll cur = SP[i - k] + (SP[N] - SP[i]) + PP[i] - PP[i - h];
      ans = max(ans, cur);
    }
    return ans;
  }
};
