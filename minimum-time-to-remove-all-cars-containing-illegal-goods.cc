const int MAX = 2e5;

class Solution {
  int ld[MAX + 10], rd[MAX + 10];
public:
  int minimumTime(string s) {
    int n = s.size(), last;
    memset(ld, 0, sizeof(ld));
    memset(rd, 0, sizeof(rd));

    last = 0;
    for (int i = 1; i <= n; i++) {
      ld[i] = ld[i - 1];
      if (s[i - 1] == '0') continue;

      ld[i] = min(i, last + 2);
      last = ld[i];
    }

    last = 0;
    for (int i = n; i >= 1; i--) {
      rd[i] = rd[i + 1];
      if (s[i - 1] == '0') continue;

      rd[i] = min(n - i + 1, last + 2);
      last = rd[i];
    }

    int ans = ld[n];
    for (int i = 1; i <= n; i++) {
      ans = min(ans, ld[i - 1] + rd[i]);
    }
    return ans;
  }
};
