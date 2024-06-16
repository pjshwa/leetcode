class Solution {
  int A[101][101];
public:
  int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
    int N = matrix.size(), M = matrix[0].size();
    memset(A, 0, sizeof(A));
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
      A[i][j] = A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1] + matrix[i - 1][j - 1];
    }

    int ans = 0;
    for (int i1 = 0; i1 < N; i1++) for (int i2 = i1 + 1; i2 <= N; i2++) {
      map<int, int> d;
      d[0] = 1;

      int cur = 0;
      for (int j = 1; j <= M; j++) {
        cur = cur + A[i2][j] - A[i1][j] - A[i2][j - 1] + A[i1][j - 1];
        ans += d[cur - target];
        d[cur]++;
      }
    }

    return ans;
  }
};
