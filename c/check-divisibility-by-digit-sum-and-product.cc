class Solution {
public:
  bool checkDivisibility(int n) {
    int s = 0, p = 1, x = n;
    while (x > 0) {
      int d = x % 10;
      s += d; p *= d; x /= 10;
    }

    int sum = s + p;
    if (sum == 0) return false;
    return n % sum == 0;
  }
};
