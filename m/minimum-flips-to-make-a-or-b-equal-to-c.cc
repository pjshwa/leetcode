class Solution {
public:
  int minFlips(int a, int b, int c) {
    int ans = 0;
    for (int i = 0; i < 30; i++) {
      int ab = (a >> i) & 1;
      int bb = (b >> i) & 1;
      int cb = (c >> i) & 1;

      if (cb == 0) ans += ab + bb;
      else ans += (ab | bb) == 0;
    }
    return ans;
  }
};
