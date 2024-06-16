const int MAX = 100, INF = 0x3f3f3f3f;

class Solution {
  vector<int> piles; int n;
  int d[MAX][MAX][2];

  int r(int i, int m, int p) {
    if (i == n) return 0;
    if (d[i][m][p] != -1) return d[i][m][p];

    int ret = p ? INF : 0, acc = 0;
    for (int v = 1; v <= 2 * m; v++) {
      if (i + v > n) break;
      acc += piles[i + v - 1];

      int nxt = r(i + v, min(n - 1, max(m, v)), 1 - p);
      if (p) ret = min(ret, nxt);
      else ret = max(ret, acc + nxt);
    }
    return d[i][m][p] = ret;
  }

public:
  int stoneGameII(vector<int>& piles) {
    this->piles = piles; n = piles.size();
    memset(d, -1, sizeof(d));
    return r(0, 1, 0);
  }
};
