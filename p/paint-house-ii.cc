const int INF = 0x3f3f3f3f;

class Solution {
public:
  int minCostII(vector<vector<int>>& costs) {
    int N = costs.size(), K = costs[0].size();
    vector<vector<int>> dp(N, vector<int>(K, INF));
    for (int j = 0; j < K; ++j) dp[0][j] = costs[0][j];

    for (int i = 1; i < N; ++i) {
      for (int pj = 0; pj < K; ++pj) for (int nj = 0; nj < K; ++nj) {
        if (pj == nj) continue;
        dp[i][nj] = min(dp[i][nj], dp[i - 1][pj] + costs[i][nj]);
      }
    }
    return *min_element(dp[N - 1].begin(), dp[N - 1].end());
  }
};
