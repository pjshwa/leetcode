using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
  ll d[1005][1005];
public:
  int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    ll s = 0;
    for (int i = 0; i < n; i++) {
      s += nums[i];
    }
    if (s < 2 * k) return 0;

    d[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int v = 0; v <= k; v++) {
        d[i][v] = d[i - 1][v];
      }
      for (int v = 0; v <= k; v++) {
        int nv = v + nums[i - 1];
        if (nv > k) nv = k;
        d[i][nv] += d[i - 1][v];
        d[i][nv] %= MOD;
      }
    }

    int deduct = 0;
    for (int i = 0; i < k; i++) {
      deduct += d[n][i];
      deduct %= MOD;
    }

    int ans = (d[n][k] - deduct + MOD) % MOD;
    return ans;
  }
};
