class Solution {
  int d[2][101][101];
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    memset(d, 0, sizeof(d));

    for (int z = 1; z <= strs.size(); z++) {
      int zc = 0, sz = strs[z - 1].size();
      for (auto c : strs[z - 1]) {
        if (c == '0') zc++;
      }

      int oc = sz - zc, x = z & 1;
      for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) d[x][i][j] = d[1 - x][i][j];
      for (int i = 0; i <= m; i++) for (int j = 0; j <= n; j++) {
        if (i < zc || j < oc) continue;
        d[x][i][j] = max(d[x][i][j], d[1 - x][i - zc][j - oc] + 1);
      }
    }
    
    return d[strs.size() % 2][m][n];
  }
};
