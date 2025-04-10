using ll = long long;

class Solution {
  int limit; string s, T;
  ll dp[20][2], N, Z;

  ll rec(int i, int f) {
    if (i == N) return 1;
    if (dp[i][f] != -1) return dp[i][f];

    ll ret = 0;
    for (int c = 0; c <= limit; ++c) {
      int p = T[i] - '0';
      if (f && c > p) break;
      if (i + Z >= N) {
        int j = i + Z - N;
        if (c != s[j] - '0') continue;
      }
      ret += rec(i + 1, f && c == p);
    }
    return dp[i][f] = ret;
  }

  ll upto(ll t) {
    T = to_string(t);
    N = T.size(), Z = s.size();
    if (t == 0 || Z > N) return 0;
    memset(dp, -1, sizeof(dp));
    return rec(0, 1);
  }

public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    this->limit = limit; this->s = s;
    return upto(finish) - upto(start - 1);
  }
};
