class Solution {
  int d[1000][1000];
  string s; int n;

  int r(int i, int j) {
    if (i > j || i < 0 || j >= n) return 0;
    if (d[i][j] != -1) return d[i][j];
    if (i == j) return d[i][j] = 1;

    int ret = max(r(i + 1, j), r(i, j - 1));
    if (s[i] == s[j]) ret = max(ret, r(i + 1, j - 1) + 2);

    return d[i][j] = ret;
  }

public:
  int longestPalindromeSubseq(string s) {
    this->s = s; n = s.size();
    memset(d, -1, sizeof(d));
    return r(0, n - 1);
  }
};
