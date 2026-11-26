class Solution {
public:
  bool canAliceWin(int n) {
    for (int i = 0; i < 10; ++i) {
      n += i - 10;
      if (n < 0) return i & 1;
    }
    return false;
  }
};
