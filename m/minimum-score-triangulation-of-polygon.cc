const int MAXN = 50;

class Solution {
  int dp[MAXN][MAXN];

  int rec(int l, int r, const vector<int>& nums) {
    if (r - l < 2) return 0;
    if (dp[l][r] != -1) return dp[l][r];
    int res = INT_MAX;
    for (int k = l + 1; k < r; ++k) {
      res = min(res, nums[l] * nums[k] * nums[r] + rec(l, k, nums) + rec(k, r, nums));
    }
    return dp[l][r] = res;
  }

public:
  int minScoreTriangulation(vector<int>& values) {
    int N = values.size();
    memset(dp, -1, sizeof dp);
    return rec(0, N - 1, values);
  }
};
