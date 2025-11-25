class Solution {
public:
  int smallestRepunitDivByK(int k) {
    int s = 0;
    for (int t = 1; t <= k; ++t) {
      s = (10 * s + 1) % k;
      if (s == 0) return t;
    }
    return -1;
  }
};
