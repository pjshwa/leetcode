#include <bits/stdc++.h>
using namespace std;

class Solution {
  int dp[11][11][11][21][2][2], k;
  string S;

  int rec(int i, int ocnt, int ecnt, int rem, int f, int lz) {
    if (dp[i][ocnt][ecnt][rem][f][lz] != -1) return dp[i][ocnt][ecnt][rem][f][lz];

    if (i == (int)S.size()) return rem == 0 && ocnt == ecnt && ocnt > 0;

    int ret = 0;
    for (int c = 0; c < 10; c++) {
      if (f && c > S[i] - '0') break;

      int nf = f && c == S[i] - '0';
      int nrem = (rem * 10 + c) % k;
      int nocnt = ocnt + (c % 2 == 1);
      int necnt = (lz && c == 0) ? ecnt : ecnt + (c % 2 == 0);

      ret += rec(i + 1, nocnt, necnt, nrem, nf, lz && c == 0);
    }

    return dp[i][ocnt][ecnt][rem][f][lz] = ret;
  }

  int upto(int n) {
    if (n == 0) return 0;

    memset(dp, -1, sizeof(dp)); S = to_string(n);
    return rec(0, 0, 0, 0, 1, 1);
  }

public:
  int numberOfBeautifulIntegers(int low, int high, int k) {
    this->k = k;
    return upto(high) - upto(low - 1);
  }
};

int main() {
  Solution sol;
  cout << sol.numberOfBeautifulIntegers(1, 10, 1) << endl;
}
