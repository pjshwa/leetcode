class Solution {
public:
  long long minEnd(int n, int x) {
    long long ans = 0, xb = 0; --n;
    for (int b = 0; b < 28; ++b) {
      while (x & (1LL << xb)) ++xb;
      if (n & (1LL << b)) ans += (1LL << xb);
      ++xb;
    }
    return ans + x;
  }
};
