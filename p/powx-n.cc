class Solution {
public:
  double myPow(double x, int n) {
    double ans = 1;
    long long k = n;
    if (n < 0) k = -k, x = 1 / x;

    while (k) {
      if (k & 1) ans *= x;
      x *= x;
      k >>= 1;
    }
    return ans;
  }
};
