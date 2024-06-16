class Solution {
  map<int, int> cache;

public:
  int minDays(int n) {
    if (n <= 2) return n;
    if (cache.count(n)) return cache[n];

    int ret = 0x3f3f3f3f;
    for (int d = 0; d <= 2; ++d) {
      if (n < d) break;

      int nn = n - d;
      if (nn % 2 == 0) ret = min(ret, minDays(nn / 2) + d + 1);
      if (nn % 3 == 0) ret = min(ret, minDays(nn / 3) + d + 1);
    }
 
    return cache[n] = ret;
  }
};
