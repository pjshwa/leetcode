class Solution {
public:
  int largestSubmatrix(vector<vector<int>>& matrix) {
    int N = matrix.size(), M = matrix[0].size(), ans = 0;
    vector<int> h(M);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; ++j) {
        h[j] = matrix[i][j] ? h[j] + 1 : 0;
      }
      vector<int> s = h;
      sort(s.begin(), s.end());
      for (int j = 0; j < M; ++j) {
        ans = max(ans, s[j] * (M - j));
      }
    }
    return ans;
  }
};
