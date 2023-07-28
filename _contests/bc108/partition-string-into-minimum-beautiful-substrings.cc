class Solution {
public:
  int minimumBeautifulSubstrings(string s) {
    int N = s.size(), ans = 0x3f3f3f3f;
    for (int state = 0; state < (1 << (N - 1)); state++) {
      int last = 0, f = 1;
      for (int i = 0; i < N - 1; i++) {
        if (state & (1 << i)) {
          if (s[last] == '0') {
            f = 0;
            break;
          }

          int num = 0;
          for (int j = last; j <= i; j++) {
            char& c = s[j];
            num = num * 2 + (c - '0');
          }
          if (num == 0) {
            f = 0;
            break;
          }

          // check if num is power of 5
          while (num % 5 == 0) num /= 5;
          if (num != 1) {
            f = 0;
            break;
          }

          last = i + 1;
        }
      }
      if (s[last] == '0') f = 0;

      int num = 0;
      for (int j = last; j < N; j++) {
        char& c = s[j];
        num = num * 2 + (c - '0');
      }
      if (num == 0) f = 0;
      while (num && num % 5 == 0) num /= 5;
      if (num != 1) f = 0;

      if (f) ans = min(ans, __builtin_popcount(state) + 1);
    }

    if (ans == 0x3f3f3f3f) return -1;
    return ans;
  }
};
