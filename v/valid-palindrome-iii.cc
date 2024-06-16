const int MAXN = 1000;

class Solution {
  int dp[MAXN][MAXN];
  string s;

  int rec(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (l >= r) return dp[l][r] = l == r;

    int ret = rec(l + 1, r);
    ret = max(ret, rec(l, r - 1));
    if (s[l] == s[r]) ret = max(ret, rec(l + 1, r - 1) + 2);
    return dp[l][r] = ret;
  }

public:
  bool isValidPalindrome(string s, int k) {
    int n = s.size(); this->s = s;
    memset(dp, -1, sizeof(dp));

    int ret = rec(0, n - 1);
    return ret + k >= n;
  }
};
