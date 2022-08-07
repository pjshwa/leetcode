const int MOD = 1e9 + 7;

class Solution {
  int d[5][20001];
public:
  int countVowelPermutation(int n) {
    for (int i = 0; i < 5; i++) d[i][1] = 1;
    for (int j = 2; j <= n; j++) {
      for (int i = 0; i < 5; i++) d[i][j] = 0;
      for (int v : {1, 2, 4}) d[0][j] = (d[0][j] + d[v][j - 1]) % MOD;
      for (int v : {0, 2}) d[1][j] = (d[1][j] + d[v][j - 1]) % MOD;
      for (int v : {1, 3}) d[2][j] = (d[2][j] + d[v][j - 1]) % MOD;
      for (int v : {2}) d[3][j] = (d[3][j] + d[v][j - 1]) % MOD;
      for (int v : {2, 3}) d[4][j] = (d[4][j] + d[v][j - 1]) % MOD;
    }

    int ans = 0;
    for (int i = 0; i < 5; i++) ans = (ans + d[i][n]) % MOD;
    return ans;
  }
};
