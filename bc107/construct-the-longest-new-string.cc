using pii = pair<int, int>;

class Solution {
  int d[51][51][51][3];

  int r(int i, int j, int k, int l) {
    if (d[i][j][k][l] != -1) return d[i][j][k][l];

    int ret = 0;
    for (auto [p, c] : {pii(0, 1), pii(1, 0), pii(1, 2), pii(2, 0), pii(2, 2)}) {
      if (p != l) continue;
      if (c == 0) {
        if (i == 0) continue;
        ret = max(ret, r(i - 1, j, k, c) + 1);
      }
      if (c == 1) {
        if (j == 0) continue;
        ret = max(ret, r(i, j - 1, k, c) + 1);
      }
      if (c == 2) {
        if (k == 0) continue;
        ret = max(ret, r(i, j, k - 1, c) + 1);
      }
    }
    return d[i][j][k][l] = ret;
  }

public:
  int longestString(int x, int y, int z) {
    memset(d, -1, sizeof(d));

    int ans = max({r(x - 1, y, z, 0), r(x, y - 1, z, 1), r(x, y, z - 1, 2)}) + 1;
    return ans * 2;
  }
};
