const int INF = 0x3f3f3f3f;

class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int N = arr.size();
    vector<int> dp(N + 1, -1); dp[0] = 0;

    for (int i = 1; i <= N; ++i) {
      int val = arr[i - 1];
      for (int d = 1; d <= k; ++d) {
        dp[i] = max(dp[i], dp[i - d] + val * d);
        if (i - d - 1 < 0) break;
        val = max(val, arr[i - d - 1]);
      }
    }
    return dp[N];
  }
};
