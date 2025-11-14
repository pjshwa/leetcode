class Solution {
public:
  vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for (const auto& q : queries) {
      int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
      ans[r1][c1] += 1;
      if (c2 + 1 < n) ans[r1][c2 + 1] -= 1;
      if (r2 + 1 < n) ans[r2 + 1][c1] -= 1;
      if (r2 + 1 < n && c2 + 1 < n) ans[r2 + 1][c2 + 1] += 1;
    }
    for (int r = 0; r < n; ++r) for (int c = 0; c < n; ++c) {
      if (r > 0) ans[r][c] += ans[r - 1][c];
      if (c > 0) ans[r][c] += ans[r][c - 1];
      if (r > 0 && c > 0) ans[r][c] -= ans[r - 1][c - 1];
    }
    return ans;
  }
};
