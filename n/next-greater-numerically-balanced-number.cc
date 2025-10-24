class Solution {
  bool isBeautiful(int num) {
    int T[10] = {0};
    while (num) ++T[num % 10], num /= 10;
    if (T[0]) return false;
    for (int i = 1; i <= 9; ++i)
      if (T[i] && T[i] != i) return false;
    return true;
  }

public:
  int nextBeautifulNumber(int n) {
    while (true) {
      n++;
      if (isBeautiful(n)) return n;
    }
  }
};
