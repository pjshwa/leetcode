const int MAXN = 1000;

class Solution {
  int C[26], V[MAXN + 1];

  void inc(int x) {
    --V[C[x]++];
    ++V[C[x]];
  }

  void dec(int x) {
    --V[C[x]--];
    ++V[C[x]];
  }

public:
  int longestBalanced(string s) {
    int N = s.size(), ans = 1;
    for (int i = 0; i < N; ++i) {
      for (int j = i; j < N; ++j) {
        int c = s[j] - 'a';
        inc(c);

        int len = j - i + 1;
        if (C[c] * V[C[c]] == len) ans = max(ans, len);
      }
      for (int j = i; j < N; ++j) {
        int c = s[j] - 'a';
        dec(c);
      }
    }
    return ans;
  }
};
