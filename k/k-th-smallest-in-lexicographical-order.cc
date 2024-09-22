class Solution {
  int dp[10][10][3], N; string S;
  int rec1(int i, int d, int f) {
    if (dp[i][d][f] != -1) return dp[i][d][f];
    if (i == N) return f <= 1;

    int ret = 1;
    for (int nd = 0; nd < 10; ++nd) {
      int c = S[i] - '0', nf = f;
      if (f == 1) {
        if (nd < c) nf = 0;
        if (nd > c) nf = 2;
      }
      ret += rec1(i + 1, nd, nf);
    }
    return dp[i][d][f] = ret;
  }

public:
  int findKthNumber(int n, int k) {
    memset(dp, -1, sizeof(dp));
    S = to_string(n); N = S.size();

    int ret = 0, f = 1;
    for (int i = 0; i < N; ++i) {
      int nf = f, cur = 0, d;
      for (d = i == 0; d < 10; ++d) {
        int c = S[i] - '0';
        if (f == 1) {
          if (d < c) nf = 0;
          if (d == c) nf = 1;
          if (d > c) nf = 2;
        }
        if (cur + rec1(i + 1, d, nf) >= k) break;
        cur += rec1(i + 1, d, nf);
      }
      k -= cur; ret = ret * 10 + d; f = nf;
      if (k == 1) return ret;
      else --k;
    }
    return ret;
  }
};
