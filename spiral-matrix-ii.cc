class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, dir = 0, si = 0, sj = 0;
    for (int i = 1; i <= n * n; i++) {
      ans[si][sj] = i;

      int ni = si + dx[dir], nj = sj + dy[dir];
      if (ni < 0 || nj < 0 || ni >= n || nj >= n || ans[ni][nj] != 0) {
        dir = (dir + 1) % 4;
        si += dx[dir], sj += dy[dir];
      }
      else si = ni, sj = nj;
    }
    return ans;
  }
};
