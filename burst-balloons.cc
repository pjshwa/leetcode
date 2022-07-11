class Solution {
  int d[501][501];
  int cost[501];
  int n;
  int max_cost(int l, int r) {
    if (l > r) return 0;
    if (d[l][r] != -1) return d[l][r];

    int ans = 0;
    for (int i = l; i <= r; i++) {
      int pv = l - 1 == 0 ? 1 : cost[l - 1];
      int nx = r == n ? 1 : cost[r + 1];

      ans = max(ans, pv * cost[i] * nx + max_cost(l, i - 1) + max_cost(i + 1, r));
    }
    return d[l][r] = ans;
  }
public:
  int maxCoins(vector<int>& nums) {
    n = nums.size();
    for (int i = 1; i <= n; i++) cost[i] = nums[i - 1];
    memset(d, -1, sizeof(d));
    return max_cost(1, n);      
  }
};
