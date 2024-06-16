class Solution {
  int dp[101][101];
  string s1, s2, s3; int N, M, L;

  int r(int i, int j) {
    if (dp[i][j] != -1) return dp[i][j];

    int k = i + j;
    if (i == N && j == M) return k == L;

    int ret = 0;
    if (i < N && k < L && s3[k] == s1[i]) ret |= r(i + 1, j);
    if (j < M && k < L && s3[k] == s2[j]) ret |= r(i, j + 1);
    return dp[i][j] = ret;
  }

public:
  bool isInterleave(string s1, string s2, string s3) {
    this->s1 = s1, this->s2 = s2, this->s3 = s3;
    N = s1.size(), M = s2.size(), L = s3.size();
    memset(dp, -1, sizeof(dp));
    return r(0, 0);
  }
};
