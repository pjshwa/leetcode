class Solution {
public:
  int longestIdealString(string s, int k) {
    int N = s.size(), P[26]; memset(P, -1, sizeof P);
    for (int i = 0; i < N; ++i) {
      int c = s[i] - 'a', u = 1;
      for (int p = c - k; p <= c + k; ++p) {
        if (p < 0 || p >= 26 || P[p] == -1) continue;
        u = max(u, P[p] + 1);
      }
      P[c] = u;
    }
    return *max_element(P, P + 26);
  }
};
