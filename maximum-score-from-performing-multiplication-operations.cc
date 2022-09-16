const int INF = 0x3f3f3f3f;

class Solution {
  // Number of operations applied, number of ops applied TO THE LEFT
  int d[1001][1001];
public:
  int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = multipliers.size(), z = nums.size();

    d[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j <= i; j++) {
      int cur = multipliers[i - 1];
      int l = j - 1, r = z - (i - j);

      d[i][j] = -INF;
      if (j) d[i][j] = max(d[i][j], d[i - 1][j - 1] + cur * nums[l]);
      if (j < i) d[i][j] = max(d[i][j], d[i - 1][j] + cur * nums[r]);
    }

    int ans = -INF;
    for (int i = 0; i <= n; i++) ans = max(ans, d[n][i]);
    return ans;
  }
};
