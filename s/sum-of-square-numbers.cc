class Solution {
public:
  bool judgeSquareSum(int c) {
    int q = sqrt(c);
    for (int a = 0; a <= q; ++a) {
      int bq = sqrt(c - a * a);
      for (int b = bq - 2; b <= bq + 2; ++b) {
        if ((long long)b * b == c - a * a) {
          return true;
        }
      }
    }
    return false;
  }
};
