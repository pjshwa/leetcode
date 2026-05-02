class Solution {
  bool is_valid(int x) {
    int ok = 0;
    while (x) {
      int d = x % 10;
      if (d == 3 || d == 4 || d == 7) return false;
      if (d == 2 || d == 5 || d == 6 || d == 9) ok = 1;
      x /= 10;
    }
    return ok;
  }

public:
  int rotatedDigits(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      if (is_valid(i)) ++ans;
    }
    return ans;
  }
};
