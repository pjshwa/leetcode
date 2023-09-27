using ll = long long;

class Solution {
  ll dp[201][201], base[201][201];

  ll r(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    ll ret = base[i][j];
    for (int k = 1; k < i; ++k) ret = max(ret, r(k, j) + r(i - k, j));
    for (int k = 1; k < j; ++k) ret = max(ret, r(i, k) + r(i, j - k));
    return dp[i][j] = ret;
  }

public:
  long long sellingWood(int m, int n, vector<vector<int>>& prices) {
    memset(dp, -1, sizeof dp); memset(base, 0, sizeof base);
    for (auto& price : prices) base[price[0]][price[1]] = price[2];
    return r(m, n);
  }
};
