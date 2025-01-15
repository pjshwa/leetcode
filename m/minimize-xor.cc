class Solution {
public:
  int minimizeXor(int num1, int num2) {
    int cnt = __builtin_popcount(num2), ans = 0;
    for (int b = 29; b >= 0; --b) {
      if (cnt == 0) break;
      int m = 1 << b;
      if ((num1 & m) || cnt > b) {
        num1 ^= m;
        ans |= m;
        --cnt;
      }
    }
    assert(cnt == 0);
    return ans;
  }
};
