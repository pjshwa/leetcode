class Solution {
public:
  int minDeletionSize(vector<string>& strs) {
    int N = strs.size(), M = strs[0].size(), ans = 0;
    vector<int> U(N, 0);
    for (int j = 0; j < M; ++j) {
      int ok = 1;
      for (int i = 1; i < N; ++i) {
        ok &= (U[i] || strs[i - 1][j] <= strs[i][j]);
      }
      if (ok) {
        for (int i = 1; i < N; ++i) U[i] |= (strs[i - 1][j] < strs[i][j]);
      } else {
        ++ans;
      }
    }
    return ans;
  }
};
