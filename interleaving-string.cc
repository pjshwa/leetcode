class Solution {
  int d[201][201];
  string S, T, U;

  bool r(int uz, int sz) {
    if (d[uz][sz] != -1) return d[uz][sz];
    if (uz == U.size()) return d[uz][sz] = (sz == S.size());

    int tz = uz - sz;
    bool res = false;
    if (sz < S.size() && U[uz] == S[sz]) res |= r(uz + 1, sz + 1);
    if (tz < T.size() && U[uz] == T[tz]) res |= r(uz + 1, sz);

    return d[uz][sz] = res;
  }

public:
  bool isInterleave(string s1, string s2, string s3) {
    memset(d, -1, sizeof(d));
    S = s1, T = s2, U = s3;

    if (S.size() + T.size() != U.size()) return false;
    return r(0, 0);
  }
};
