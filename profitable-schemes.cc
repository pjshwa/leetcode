const int MOD = 1e9 + 7;

class Solution {
public:
  int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
    int d[n + 1][minProfit + 1];
    memset(d, 0, sizeof(d)); d[0][0] = 1;

    int z = group.size();
    for (int i = 0; i < z; i++) {
      int g = group[i], p = profit[i];
      for (int pg = n - g; pg >= 0; pg--) for (int pp = minProfit; pp >= 0; pp--) {
        int ng = pg + g, np = min(pp + p, minProfit);
        d[ng][np] = (d[ng][np] + d[pg][pp]) % MOD;
      }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) ans = (ans + d[i][minProfit]) % MOD;
    return ans;
  }
};
