const int MAX = 2000;

class Solution {
  int d[MAX + 1][MAX + 1], Z1, Z2;
  string s, p;

  bool r(int i, int j) {
    if (d[i][j] != -1) return d[i][j];
    if (j == Z2) return d[i][j] = i == Z1;

    bool ret = false;
    if (i < Z1 && (s[i] == p[j] || p[j] == '?' || p[j] == '*')) ret |= r(i + 1, j + 1);
    if (p[j] == '*') {
      if (i < Z1) ret |= r(i + 1, j);
      ret |= r(i, j + 1);
    }
    return d[i][j] = ret;
  }

public:
  bool isMatch(string s, string p) {
    Z1 = s.size(), Z2 = p.size();
    this->s = s, this->p = p;
    for (int i = 0; i <= Z1; i++) fill(d[i], d[i] + Z2 + 1, -1);
    return r(0, 0);
  }
};
