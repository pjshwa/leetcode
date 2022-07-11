class Solution {
  // last index, neighbor count, last color
  int d[101][101][21];

public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    swap(m, n);  
    for (int i = 0; i <= n; i++) for (int nc = 0; nc <= n; nc++) fill(d[i][nc], d[i][nc] + m + 1, 0x3f3f3f3f);
    d[0][0][0] = 0;

    for (int i = 1; i <= n; i++) for (int nc = 1; nc <= target; nc++) {
      int hcol = houses[i - 1];
      if (hcol) {
        for (int pcol = 0; pcol <= m; pcol++) {
          if (pcol == hcol) d[i][nc][hcol] = min(d[i][nc][hcol], d[i - 1][nc][pcol]);
          else if (nc > 0) d[i][nc][hcol] = min(d[i][nc][hcol], d[i - 1][nc - 1][pcol]);
        }
      }
      else {

        for (int pcol = 0; pcol <= m; pcol++) for (int ncol = 1; ncol <= m; ncol++) {
          int tcost = cost[i - 1][ncol - 1];
          if (pcol == ncol) d[i][nc][ncol] = min(d[i][nc][ncol], d[i - 1][nc][pcol] + tcost);
          else if (nc > 0) d[i][nc][ncol] = min(d[i][nc][ncol], d[i - 1][nc - 1][pcol] + tcost);
        }
      }

    }

    int res = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) res = min(res, d[n][target][i]);

    if (res == 0x3f3f3f3f) return -1;
    return res;
  }
};
