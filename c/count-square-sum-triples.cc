class Solution {
public:
  int countTriples(int n) {
    int ans = 0;
    for (int a = 1; a <= n; ++a) for (int b = 1; b <= n; ++b) {
      int c2 = a * a + b * b;
      int q = sqrt(c2);
      for (int c = q - 1; c <= q + 1; ++c) {
        if (c * c == c2 && c <= n) ++ans;
      }
    }
    return ans;
  }
};
