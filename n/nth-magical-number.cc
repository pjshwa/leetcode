const int MOD = 1e9 + 7;
using ll = long long;

class Solution {
public:
  int nthMagicalNumber(int n, int a, int b) {
    int g = __gcd(a, b), l = a / g * b;

    ll left = 1, right = 3e18;
    while (left < right) {
      ll mid = (left + right) / 2;
      if (mid / a + mid / b - mid / l < n) left = mid + 1;
      else right = mid;
    }

    return left % MOD;
  }
};
