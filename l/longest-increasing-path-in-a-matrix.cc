const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

class Solution {
  int d[200][200], n, m;

  int r(int i, int j, vector<vector<int>>& a) {
    if (d[i][j] != -1) return d[i][j];

    int res = 1, cur = 0;
    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k], nj = j + dy[k];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
      if (a[ni][nj] > a[i][j]) cur = max(cur, r(ni, nj, a));
    }

    return d[i][j] = res + cur;
  }
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    n = matrix.size(), m = matrix[0].size();
    memset(d, -1, sizeof d);

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) ans = max(ans, r(i, j, matrix));

    return ans;
  }
};
