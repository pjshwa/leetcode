class Solution {
  int A[101][101];
public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    memset(A, 0, sizeof(A));
    int N = matrix.size(), M = matrix[0].size();
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
      A[i][j] = A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1] + matrix[i - 1][j - 1];
    }

    int ans = -0x3f3f3f3f;
    for (int i1 = 0; i1 < N; i1++) for (int i2 = i1 + 1; i2 <= N; i2++) {
      set<int> s{0};

      int cur = 0;
      for (int j = 1; j <= M; j++) {
        cur += A[i2][j] - A[i1][j] - A[i2][j - 1] + A[i1][j - 1];
        auto it = s.lower_bound(cur - k);
        if (it != s.end()) ans = max(ans, cur - *it);
        s.insert(cur);
      }
    }

    return ans;
  }
};
