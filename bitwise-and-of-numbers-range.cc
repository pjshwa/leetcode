class Solution {
public:
  int rangeBitwiseAnd(int left, int right) {
    int ans = 0;
    for (int b = 30; b >= 0; --b) {
      int li = left >> b & 1;
      int ri = right >> b & 1;

      if (li == ri) ans |= li << b;
      else break;
    }
    return ans;
  }
};
