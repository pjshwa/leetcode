class Solution {
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    int M = box.size(), N = box[0].size();
    vector<vector<char>> res(N, vector<char>(M));
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      res[i][j] = box[M - 1 - j][i];
    }

    for (int j = 0; j < M; ++j) {
      int p = N - 1;
      for (int i = N - 1; i >= 0; --i) {
        if (res[i][j] == '*') p = i - 1;
        else if (res[i][j] == '#') {
          res[i][j] = '.';
          res[p--][j] = '#';
        }
      }
    }
    return res;
  }
};
