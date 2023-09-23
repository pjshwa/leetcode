const int MOD = 1e9 + 7;

class Solution {
  string S;
  int d[100][10][2][2];

  int r(int i, int l, int f, int lz) {
    if (i == S.size()) return 1;
    if (d[i][l][f][lz] != -1) return d[i][l][f][lz];

    int ret = 0;
    for (int c = 0; c < 10; ++c) {
      if (f && c < S[i] - '0') continue;
      if (i == 0 || lz || abs(l - c) == 1) {
        ret = (ret + r(i + 1, c, f && c == S[i] - '0', lz && c == 0)) % MOD;
      }
    }
    return d[i][l][f][lz] = ret;
  }

  bool is_stepping(string& num) {
    for (int i = 1; i < num.size(); ++i) {
      if (abs(num[i] - num[i - 1]) != 1) return false;
    }
    return true;
  }

public:
  int countSteppingNumbers(string low, string high) {
    S = low; memset(d, -1, sizeof d);
    int v1 = r(0, 0, 1, 1);

    S = high; memset(d, -1, sizeof d);
    int v2 = r(0, 0, 1, 1);

    int ans = (v2 - v1) % MOD;
    if (is_stepping(low)) ans = (ans + 1) % MOD;
    return ans;
  }
};
