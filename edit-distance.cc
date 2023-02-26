const int MAX = 500;

class Solution {
  int d[MAX + 5][MAX + 5];
  int n, m; string word1, word2;

  int r(int i, int j) {
    if (d[i][j] != -1) return d[i][j];
    if (i == n) {
      if (j == m) return d[i][j] = 0;
      else return d[i][j] = 1 + r(i, j + 1);
    }
    else if (j == m) return d[i][j] = 1 + r(i + 1, j);

    int ret = r(i + 1, j + 1) + (word1[i] != word2[j]);
    ret = min(ret, r(i + 1, j) + 1);
    ret = min(ret, r(i, j + 1) + 1);
    return d[i][j] = ret;
  }

public:
  int minDistance(string word1, string word2) {
    n = word1.size(), m = word2.size();
    this->word1 = word1, this->word2 = word2;
    memset(d, -1, sizeof(d));
    return r(0, 0);
  }
};
