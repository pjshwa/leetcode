class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int N = matrix.size(), M = matrix[0].size();

    bool firstRowZero = false;
    for (int j = 0; j < M; ++j) firstRowZero |= matrix[0][j] == 0;

    for (int i = 1; i < N; ++i) {
      bool isZero = false;
      for (int j = 0; j < M; ++j) isZero |= matrix[i][j] == 0;
      if (!isZero) continue;
      for (int j = 0; j < M; ++j) {
        if (matrix[i][j] == 0) matrix[0][j] = 0;
        else matrix[i][j] = 0;
      }
    }

    for (int j = 0; j < M; ++j) {
      if (matrix[0][j] != 0) continue;
      for (int i = 1; i < N; ++i) matrix[i][j] = 0;
    }
    if (firstRowZero) {
      for (int j = 0; j < M; ++j) matrix[0][j] = 0;
    }
  }
};
