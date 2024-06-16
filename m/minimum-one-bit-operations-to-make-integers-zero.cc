class Solution {
public:
  int minimumOneBitOperations(int n) {
    bool f = true; int ans = 0;
    for (int b = 29; b >= 0; --b) {
      if (!(n & (1 << b))) continue;
      int val = (1 << (b + 1)) - 1;
      if (f) ans += val;
      else ans -= val;
      f = !f;
    }
    return ans;
  }
};
