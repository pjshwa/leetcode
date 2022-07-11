class Solution {
  int total;
  double d[101][101];

  double r(int qr, int qg) {
    if (d[qr][qg] != -1) return d[qr][qg];

    double res;
    if (qr == 0) res = total;
    else {
      double left = 0, right = 0;
      if (qg > 0) left = r(qr - 1, qg - 1);
      if (qg < qr) right = r(qr - 1, qg);

      left = (left - min(left, 1.0)) / 2;
      right = (right - min(right, 1.0)) / 2;
      res = left + right;
    }

    return d[qr][qg] = res;
  }
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    total = poured;
    for (int i = 0; i <= 100; i++) for (int j = 0; j <= i; j++) d[i][j] = -1;
    double res = r(query_row, query_glass);
    return min(res, 1.0);
  }
};
