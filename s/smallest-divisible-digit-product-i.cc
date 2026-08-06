class Solution {
  int getDigitProduct(int n) {
    int ret = 1;
    while (n) {
      ret *= (n % 10);
      n /= 10;
    }
    return ret;
  }

public:
  int smallestNumber(int n, int t) {
    while (getDigitProduct(n) % t != 0) ++n;
    return n;
  }
};
