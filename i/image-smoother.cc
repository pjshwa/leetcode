const int dx[] = {0, 0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {0, 1, -1, 0, 0, 1, -1, 1, -1};

class Solution {
public:
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int N = img.size(), M = img[0].size();
    vector<vector<int>> ans(N, vector<int>(M));

    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
      int sum = 0, cnt = 0;
      for (int k = 0; k < 9; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < N && y >= 0 && y < M) {
          sum += img[x][y];
          ++cnt;
        }
      }
      ans[i][j] = sum / cnt;
    }
    return ans;
  }
};
