class Solution {
public:
  int countVowelStrings(int n) {
    int d[51][5];
    memset(d, 0, sizeof(d));
    for (int j = 0; j < 5; j++) d[1][j] = 1;

    for (int i = 2; i <= n; i++) {
      d[i][0] = d[i - 1][0];
      d[i][1] = d[i - 1][0] + d[i - 1][1];
      d[i][2] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2];
      d[i][3] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2] + d[i - 1][3];
      d[i][4] = d[i - 1][0] + d[i - 1][1] + d[i - 1][2] + d[i - 1][3] + d[i - 1][4];
    }

    return d[n][0] + d[n][1] + d[n][2] + d[n][3] + d[n][4];
  }
};
