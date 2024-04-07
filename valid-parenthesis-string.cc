class Solution {
public:
  bool checkValidString(string s) {
    int N = s.size();

    int dp[N + 1][N + 1];
    memset(dp, -1, sizeof(dp));

    function<int(int, int)> rec = [&](int i, int o) {
      if (i == N) return o == 0 ? 1 : 0;
      if (dp[i][o] != -1) return dp[i][o];

      int ret = 0;
      if (s[i] == '(') ret = rec(i + 1, o + 1);
      else if (s[i] == ')') {
        if (o) ret = rec(i + 1, o - 1);
      }
      else {
        ret = rec(i + 1, o + 1) || rec(i + 1, o);
        if (o) ret |= rec(i + 1, o - 1);
      }
      return dp[i][o] = ret;
    };

    return rec(0, 0);
  }
};
