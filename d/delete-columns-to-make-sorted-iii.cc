class Solution {
public:
  int minDeletionSize(vector<string>& strs) {
    int N = strs.size(), M = strs[0].size();
    vector<int> dp(M, 1);
    for (int i = 1; i < M; ++i) for (int j = 0; j < i; ++j) {
      bool ok = true;
      for (int k = 0; k < N; ++k) ok &= (strs[k][j] <= strs[k][i]);
      if (ok) dp[i] = max(dp[i], dp[j] + 1);
    }
    return M - *max_element(dp.begin(), dp.end());
  }
};
