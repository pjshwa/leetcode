const int MAXN = 300;

class Solution {
  int P[MAXN + 1][MAXN + 1];

public:
  int countSquares(vector<vector<int>>& matrix) {
    memset(P, 0, sizeof(P));
    int N = matrix.size(), M = matrix[0].size();
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) {
      P[i][j] = matrix[i - 1][j - 1] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
    }

    int ans = 0;
    for (int k = 1; k <= min(N, M); ++k) {
      for (int i = k; i <= N; i++) for (int j = k; j <= M; j++) {
        if (P[i][j] - P[i - k][j] - P[i][j - k] + P[i - k][j - k] == k * k) {
          ans++;
        }
      }
    }
    return ans;
  }
};
