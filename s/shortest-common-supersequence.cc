const int MAXN = 1000;

class Solution {
  string str1, str2, ans = "";
  int Z1, Z2, dp[MAXN][MAXN];

  int rec(int i1, int i2) {
    if (i1 == Z1 || i2 == Z2) return (Z1 + Z2 - i1 - i2);
    if (dp[i1][i2] != -1) return dp[i1][i2];

    int ret;
    if (str1[i1] == str2[i2]) ret = 1 + rec(i1 + 1, i2 + 1);
    else ret = min(rec(i1 + 1, i2), rec(i1, i2 + 1)) + 1;
    return dp[i1][i2] = ret;
  }

  void trace(int i1, int i2) {
    if (i1 == Z1) {
      if (i2 == Z2) return;
      ans += str2[i2];
      return trace(i1, i2 + 1);
    } else if (i2 == Z2) {
      ans += str1[i1];
      return trace(i1 + 1, i2);
    }

    if (str1[i1] == str2[i2]) {
      ans += str1[i1];
      return trace(i1 + 1, i2 + 1);
    } else if (rec(i1 + 1, i2) < rec(i1, i2 + 1)) {
      ans += str1[i1];
      return trace(i1 + 1, i2);
    } else {
      ans += str2[i2];
      return trace(i1, i2 + 1);
    }
  }

public:
  string shortestCommonSupersequence(string str1, string str2) {
    this->str1 = str1; this->str2 = str2;
    Z1 = str1.size(); Z2 = str2.size();

    memset(dp, -1, sizeof(dp));
    trace(0, 0);
    return ans;
  }
};
