class Solution {
  vector<int> stoneValue;
  vector<vector<int>> dp;

  int rec(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int sum = 0, acc_l = 0;
    for (int i = l; i <= r; ++i) sum += stoneValue[i];

    int ret = 0;
    for (int p = l; p < r; ++p) {
      acc_l += stoneValue[p];
      int acc_r = sum - acc_l;
      
      if (acc_l < acc_r) ret = max(ret, acc_l + rec(l, p));
      else if (acc_l > acc_r) ret = max(ret, acc_r + rec(p + 1, r));
      else ret = max(ret, acc_l + max(rec(l, p), rec(p + 1, r)));
    }

    return dp[l][r] = ret;
  }

public:
  int stoneGameV(vector<int>& stoneValue) {
    this->stoneValue = stoneValue;

    int n = stoneValue.size();
    dp.resize(n, vector<int>(n, -1));

    return rec(0, n - 1);
  }
};
