const int INF = 0x3f3f3f3f;

class Solution {
  int d[500][500]; string s;
  int r(int i, int j) {
    if (d[i][j] != -1) return d[i][j];
    if (i >= j) return d[i][j] = 0;
    
    int ret = INF;
    if (s[i] == s[j]) ret = min(ret, r(i + 1, j - 1));
    else ret = min(ret, min(r(i + 1, j), r(i, j - 1)) + 1);
    return d[i][j] = ret;
  }

public:
  int minInsertions(string s) {
    memset(d, -1, sizeof(d));
    this->s = s;
    return r(0, s.size() - 1);
  }
};
