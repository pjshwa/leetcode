class Solution {
public:
  bool isPowerOfFour(int n) {
    if (n <= 0) return false;
    n = abs(n);

    bool pw2 = !(n & (n - 1));
    return pw2 && (n & 0x55555555);
  }
};
