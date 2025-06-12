const int MAXN = 3e4, INF = 0x3f3f3f3f;

class Solution {
  int T[4][MAXN + 1], P[5][MAXN + 1];

public:
  int maxDifference(string s, int k) {
    int N = s.size(), ans = -INF;

    for (char a = '0'; a < '5'; ++a) {
      P[a - '0'][0] = 0;
      for (int i = 1; i <= N; ++i) {
        P[a - '0'][i] = P[a - '0'][i - 1] + (s[i - 1] == a);
      }
    }

    for (char a = '0'; a < '5'; ++a) for (char b = '0'; b < '5'; ++b) {
      if (a == b) continue;

      memset(T, 0x3f, sizeof(T)); T[0][0] = 0;
      int dif = 0, sta = 0, l = 0;
      for (int i = 1; i <= N; ++i) {
        char c = s[i - 1];
        if (c == a) ++dif, sta ^= 1;
        if (c == b) --dif, sta ^= 2;
        while (P[b - '0'][i] - P[b - '0'][l] >= 2) ++l;

        T[sta][i] = min(T[sta][i], dif);
        for (int j = 0; j < 4; ++j) {
          T[j][i] = min(T[j][i], T[j][i - 1]);
        }
        if (i >= k && P[b - '0'][i] >= 2) {
          ans = max(ans, dif - T[sta ^ 1][min(i - k, l - 1)]);
        }
      }
    }
    return ans;
  }
};
