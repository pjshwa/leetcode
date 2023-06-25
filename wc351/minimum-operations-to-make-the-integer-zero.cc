using ll = long long;

class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    for (int t = 1; t <= 5e6; t++) {
      ll target = (ll)num1 - (ll)num2 * (ll)t;
      if (target < 0) break;

      ll mmax = 0, pw = 1, mmin = __builtin_popcountll(target);
      while (target) {
        if (target & 1) mmax += pw;
        target >>= 1; pw <<= 1;
      }

      if (mmin <= t && t <= mmax) return t;
    }
    return -1;
  }
};
